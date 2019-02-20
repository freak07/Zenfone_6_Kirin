// SPDX-License-Identifier: GPL-2.0
#include <linux/cpufreq.h>

static struct cpufreq_frequency_table freq_table[] = {
	{ .frequency = 1 },
	{ .frequency = 2 },
	{ .frequency = CPUFREQ_TABLE_END },
};

static int dummy_cpufreq_target_index(struct cpufreq_policy *policy,
				   unsigned int index)
{
	return 0;
}

static int dummy_cpufreq_driver_init(struct cpufreq_policy *policy)
{
	return cpufreq_table_validate_and_show(policy, freq_table);
}

static int dummy_cpufreq_verify(struct cpufreq_policy *policy)
{
	return 0;
}

static struct cpufreq_driver dummy_cpufreq_driver = {
	.name = "dummy",
	.target_index = dummy_cpufreq_target_index,
	.init = dummy_cpufreq_driver_init,
	.verify = dummy_cpufreq_verify,
	.attr = cpufreq_generic_attr,
};

static int __init dummy_cpufreq_init(void)
{
	return cpufreq_register_driver(&dummy_cpufreq_driver);
}

late_initcall(dummy_cpufreq_init);
