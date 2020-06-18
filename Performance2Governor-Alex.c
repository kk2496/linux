/*
 *  linux/drivers/cpufreq/cpufreq_performance.c
 *
 *  Copyright (C) 2002 - 2003 Dominik Brodowski <linux@brodo.de>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/cpufreq.h>
#include <linux/init.h>
#include "cpufreq_governor.h"
#include <linux/workqueue.h>
#include <linux/slab.h>


typedef struct {
	 struct cpufreq_policy *policy2;
	 struct delayed_work my_work;
}dem;
//dem *var1,*var2;

static struct workqueue_struct *my_wq;

//static void func1(struct delayed_work *work){
//	dem *var3=container_of(work, dem, my_work);
//	__cpufreq_driver_target(var3->policy2, 1800000,	CPUFREQ_RELATION_H);
//	printk(KERN_INFO " inside fn func\n");
//}
static void func2(struct delayed_work *work){
        dem *var3=container_of(work, dem, my_work);
        __cpufreq_driver_target(var3->policy2, 1600000, CPUFREQ_RELATION_H);
       // printk(KERN_INFO " inside fn func\n");
}
static void func3(struct delayed_work *work){
        dem *var3=container_of(work, dem, my_work);
        __cpufreq_driver_target(var3->policy2, 1900000, CPUFREQ_RELATION_H);
       // printk(KERN_INFO " inside fn func\n");
}
static void func4(struct delayed_work *work){
        dem *var3=container_of(work, dem, my_work);
        __cpufreq_driver_target(var3->policy2, 1500000, CPUFREQ_RELATION_H);
        //printk(KERN_INFO " inside fn func\n");
}
static void func5(struct delayed_work *work){
        dem *var3=container_of(work, dem, my_work);
        __cpufreq_driver_target(var3->policy2, 1900000, CPUFREQ_RELATION_H);
       // printk(KERN_INFO " inside fn func\n");
}

static int cpufreq_governor_performance2(struct cpufreq_policy *policy,
					unsigned int event)
{
	switch (event) {
	case CPUFREQ_GOV_START:
	case CPUFREQ_GOV_LIMITS:
		my_wq=create_workqueue("mwq");
	       // printk(KERN_INFO "created wq \n");
		pr_debug("setting to %u kHz because of event %u\n",
						policy->max, event);
		__cpufreq_driver_target(policy, 1800000,
						CPUFREQ_RELATION_H);
	        //printk(KERN_INFO " changed fr \n");
	       
 dem *fvar2 = (dem *)kmalloc(sizeof(dem), GFP_KERNEL);
  fvar2->policy2=policy;
INIT_DELAYED_WORK(&fvar2->my_work,func2);
queue_delayed_work_on(4,my_wq, &fvar2->my_work, usecs_to_jiffies(22700));

 dem *fvar3 = (dem *)kmalloc(sizeof(dem), GFP_KERNEL);
 dem *fvar4 = (dem *)kmalloc(sizeof(dem), GFP_KERNEL);
 dem *fvar5 = (dem *)kmalloc(sizeof(dem), GFP_KERNEL);

 // printk(KERN_INFO " inside fn func\n");
                fvar3->policy2=policy;
                fvar4->policy2=policy;
                fvar5->policy2=policy;

	//	printk(KERN_INFO " transf pol \n");
INIT_DELAYED_WORK(&fvar3->my_work,func3);
queue_delayed_work_on(4,my_wq, &fvar3->my_work, usecs_to_jiffies(56120));
INIT_DELAYED_WORK(&fvar4->my_work,func4);
queue_delayed_work_on(4,my_wq, &fvar4->my_work, usecs_to_jiffies(67170));
INIT_DELAYED_WORK(&fvar5->my_work,func5);
queue_delayed_work_on(4,my_wq, &fvar5->my_work, usecs_to_jiffies(118000));



//		mod_delayed_work_on(5, system_wq, &fvar->my_work, usecs_to_jiffies(10000));
//		mod_delayed_work_on(6, system_wq, &fvar->my_work, usecs_to_jiffies(10000));
//		mod_delayed_work_on(7, system_wq, &fvar->my_work, usecs_to_jiffies(10000));
	

		break;
	default:
		break;
	}
	return 0;
}

#ifdef CONFIG_CPU_FREQ_GOV_PERFORMANCE2_MODULE
static
#endif
struct cpufreq_governor cpufreq_gov_performance2 = {
	.name		= "performance2",
	.governor	= cpufreq_governor_performance2,
	.owner		= THIS_MODULE,
};


static int __init cpufreq_gov_performance2_init(void)
{
	return cpufreq_register_governor(&cpufreq_gov_performance2);
}


static void __exit cpufreq_gov_performance2_exit(void)
{
	cpufreq_unregister_governor(&cpufreq_gov_performance2);
}


MODULE_AUTHOR("Dominik Brodowski <linux@brodo.de>");
MODULE_DESCRIPTION("CPUfreq policy governor 'performance2'");
MODULE_LICENSE("GPL");

fs_initcall(cpufreq_gov_performance2_init);
module_exit(cpufreq_gov_performance2_exit);

