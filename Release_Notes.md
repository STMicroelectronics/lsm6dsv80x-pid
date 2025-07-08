---
pagetitle: Release Notes for LSM6DSV80X Component
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for LSM6DSV80X Component Driver
Copyright &copy; 2022 STMicroelectronics\

[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>

# License

This software component is licensed by ST under BSD 3-Clause license, the "License".
You may not use this component except in compliance with the License. You may obtain a copy of the License at:

[BSD 3-Clause license](https://opensource.org/licenses/BSD-3-Clause)

# Purpose

This directory contains the LSM6DSV80X component drivers.
:::

::: {.col-sm-12 .col-lg-8}
# Update history

::: {.collapse}
<input type="checkbox" id="collapse-section1" aria-hidden="true">
<label for="collapse-section1" aria-hidden="true">V1.0.0 / 21-Mar-2025</label>
<div>

## Main changes

### First release

- First official release [ref. DS v1.0]

##

</div>

<input type="checkbox" id="collapse-section2" checked aria-hidden="true">
<label for="collapse-section2" aria-hidden="true">V1.1.0 / 07-Jul-2025</label>
<div>

## Main changes

- Fix driver formatting options
- Added pointer to private data in stmdev_ctx_t
- Fix setting of few embedded registers
- Fix wrong ODR enums values for HA02 and add HA03
- Fix wrong address for register EMB_FUNC_SENSOR_CONV_EN
- Set ois_drdy parameter in filt_settling_mask_get()
- add from_f16_to_f32 API
- fix fifo_fsm_batch_set/get APIs
- Fix typo in fifo_out_raw_get() API

##

</div>
:::




:::
:::

<footer class="sticky">
::: {.columns}
::: {.column width="95%"}
For complete documentation on LSM6DSV80X,
visit:
[LSM6DSV80X](https://www.st.com/content/st_com/en/products/mems-and-sensors/inemo-inertial-modules/lsm6dsv80x.html)
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 1.0">Info</abbr>
:::
:::
</footer>
