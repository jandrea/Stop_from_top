from ROOT import gROOT, TCanvas, TF1, TH1F, TFile, TGraph
from array import array

import numpy as n



options = Options()
options.set('minimizer', 'strategy', 'newton_vanilla')



# for model building:
def get_model(signalname):

    # Read in and build the model automatically from the histograms in the root file. 
    # This model will contain all shape uncertainties given according to the templates
    # which also includes rate changes according to the alternate shapes.
    # For more info about this model and naming conventuion, see documentation
    # of build_model_from_rootfile.
    
    model = build_model_from_rootfile('ThetaFile_cutbased.root',  include_mc_uncertainties=False)

    # If the prediction histogram is zero, but data is non-zero, teh negative log-likelihood
    # is infinity which causes problems for some methods. Therefore, we set all histogram
    # bin entries to a small, but positive value:
    model.fill_histogram_zerobins()

    # define what the signal processes are. All other processes are assumed to make up the 
    # 'background-only' model.
    model.set_signal_processes('susy175')

    # Add some lognormal rate uncertainties. The first parameter is the name of the
    # uncertainty (which will also be the name of the nuisance parameter), the second
    # is the 'effect' as a fraction, the third one is the process name. The fourth parameter
    # is optional and denotes the channl. The default '*' means that the uncertainty applies
    # to all channels in the same way.
    # Note that you can use the same name for a systematic here as for a shape
    # systematic. In this case, the same parameter will be used; shape and rate changes 
    # will be 100% correlated.
    
    model.add_lognormal_uncertainty('singletop_rate', math.log(1.22), 'singletop')
    model.add_lognormal_uncertainty('dy_rate',   math.log(1.21), 'dy'  )
    #model.add_lognormal_uncertainty('dy_rate',   math.log(10.), 'dy'  )
    #model.distribution.set_distribution_parameters('dy_rate', width=1000000) 
    
    model.add_lognormal_uncertainty('rare_rate', math.log(1.20), 'rare')
    #model.add_lognormal_uncertainty('fake_rate', math.log(1.99), 'fake')
    model.add_lognormal_uncertainty('vv_rate',   math.log(1.22), 'vv'  )
    model.add_lognormal_uncertainty('ttbar_rate',   math.log(1.09), 'vv'  )
    #model.add_lognormal_uncertainty('ww_rate',   math.log(1.23), 'ww'  )
    #model.add_lognormal_uncertainty('zz_rate',   math.log(1.23), 'zz'  )
    #model.add_lognormal_uncertainty('wz_rate',   math.log(1.23), 'wz'  )

	

	
	
    # the qcd model is from data, so do not apply a lumi uncertainty on that:
    for p in model.processes:
    
    	if p == 'dy': continue
    	if p == 'fake': continue
    	model.add_lognormal_uncertainty('lumi',        math.log(1.026), p)
        model.add_lognormal_uncertainty('TrigLept',    math.log(1.013), p)
	
	
	
        #model.add_lognormal_uncertainty('Brs',     math.log(1.05) , p)
    # Specifying all uncertainties manually can be error-prone. You can also execute
    # a automatically generated file using python's execfile here
    # which contains these statements, or read in a text file, etc. Remember: this is a
    # python script, so use this power!
    return model

# -------------- TO CHANGE BY THE USER
signalname = 'susy175'
# -------------- TO CHANGE BY THE USER
model = get_model(signalname)


# first, it is a good idea to generate a summary report to make sure everything has worked
# as expected. The summary will generate quite some information which should it make easy to spot
# errors like typos in the name of uncertainties, missing shape uncertaintie, etc.
model_summary(model)




# 2.b. CLs limits
# calculate cls limit plots. The interface is very similar to bayesian_limits. However, there are a few
# more options such as the definition of the test statistic which is usually a likelihood ratio but can differ in
# which parameters are minimized and which constraints / ranges are applied during minimization.
# Here, we stay with the default which fixes beta_signal=0
# for the background only hypothesis and lets it float freely for the signal+background hypothesis.
# See cls_limits documentation for more options.

# la ligne ci dessous ne fonctionne pas=> changer directement cls_limit.py

# ------------------- TO CHANGE BY THE USER
#xsections = ['05','10','20','30','50']
#xsections = ['10','20','30','50']
# ------------------- TO CHANGE BY THE USER

#xsections2 = []
#for item in xsections :
#    tmp=[]
#    tmp.append('FCNC_'+signalname+item)
#    xsections2.append(tmp)
#print "Signal processes : " + str(xsections2)

options = Options()
#options.set('minimizer', 'minuit_tolerance_factor', '1000')
#options.set("newton", "use_nll_der", "False")
#options.set('main', 'n_threads', '15')


#options.set('minimizer', 'strategy', 'newton_vanilla')  


#plot_exp, plot_obs = cls_limits(model, signal_processes = xsections2)

singnal_shapes = {'susy175': ['susy175']}  

fit = mle(model, 'data', n = 1, signal_process_groups = singnal_shapes, with_covariance=True, with_error=True)


parameter_values = {}
parameter_uncert = {}
for p in model.get_parameters([]):
    parameter_values[p] = fit['susyStop200'][p][0][0]
    parameter_uncert[p] = fit['susyStop200'][p][0][1]
    
    print [p, parameter_values[p], parameter_uncert[p] ]
    

 
histos = evaluate_prediction(model, parameter_values, include_signal = False)
write_histograms_to_rootfile(histos, 'histos-mle_susyStop.root')  


#signal_process_groups_bck = {'FCNC_zut05': []}
#histos_uncertainty = bayesian_posterior_model_prediction(model, "data", 1, signal_process_groups = signal_process_groups_bck)
#val    = histos_uncertainty["FCNC_zut05"]["MVABDT"][0].get_values() 
#uncert = histos_uncertainty["FCNC_zut05"]["MVABDT"][0].get_uncertainties() 
#print [uncert]


#plot_exp, plot_obs = cls_limits(model, signal_process_groups =   singnal_shapes, frequentist_bootstrapping=False)
plot_exp, plot_obs = cls_limits(model, signal_process_groups =   singnal_shapes, options = options)
#plot_exp, plot_obs = cls_limits(model, signal_process_groups =   singnal_shapes)


plot_exp.write_txt('cls_limits_expected_susy175.txt')
plot_obs.write_txt('cls_limits_observed_susy175.txt')



### For max. Likelihood Fit results
### For max. Likelihood Fit results
### For max. Likelihood Fit results
### For max. Likelihood Fit results



### For profile likelihood intervals
### For profile likelihood intervals
### For profile likelihood intervals
### For profile likelihood intervals

#fit = pl_interval(model, 'data', n = 1,signal_process_groups = singnal_shapes )
#parameter_clsUp = {}
#parameter_clsDown = {}
#for p in model.get_parameters([]):
    #parameter_clsUp[p] = fit['FCNC_zut05'][p]
    #parameter_clsDown = fit['FCNC_zut05'][p][0][1]
    #print p
    #print [p, parameter_values[p], parameter_uncert[p] ]
    
#histos = evaluate_prediction(model, parameter_values, include_signal = False)
#write_histograms_to_rootfile(histos, 'histos-mle.root')



report = model_summary(model)
#report.write_html('htmlout')


