/**
  ******************************************************************************
  * @file    lsm6dsv80x_reg.h
  * @author  Sensors Software Solution Team
  * @brief   This file contains all the functions prototypes for the
  *          lsm6dsv80x_reg.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef LSM6DSV80X_REGS_H
#define LSM6DSV80X_REGS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include <math.h>

/** @addtogroup LSM6DSV80X
  * @{
  *
  */

/** @defgroup  Endianness definitions
  * @{
  *
  */

#ifndef DRV_BYTE_ORDER
#ifndef __BYTE_ORDER__

#define DRV_LITTLE_ENDIAN 1234
#define DRV_BIG_ENDIAN    4321

/** if _BYTE_ORDER is not defined, choose the endianness of your architecture
  * by uncommenting the define which fits your platform endianness
  */
//#define DRV_BYTE_ORDER    DRV_BIG_ENDIAN
#define DRV_BYTE_ORDER    DRV_LITTLE_ENDIAN

#else /* defined __BYTE_ORDER__ */

#define DRV_LITTLE_ENDIAN  __ORDER_LITTLE_ENDIAN__
#define DRV_BIG_ENDIAN     __ORDER_BIG_ENDIAN__
#define DRV_BYTE_ORDER     __BYTE_ORDER__

#endif /* __BYTE_ORDER__*/
#endif /* DRV_BYTE_ORDER */

/**
  * @}
  *
  */

/** @defgroup STMicroelectronics sensors common types
  * @{
  *
  */

#ifndef MEMS_SHARED_TYPES
#define MEMS_SHARED_TYPES

typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t bit0                         : 1;
  uint8_t bit1                         : 1;
  uint8_t bit2                         : 1;
  uint8_t bit3                         : 1;
  uint8_t bit4                         : 1;
  uint8_t bit5                         : 1;
  uint8_t bit6                         : 1;
  uint8_t bit7                         : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bit7                         : 1;
  uint8_t bit6                         : 1;
  uint8_t bit5                         : 1;
  uint8_t bit4                         : 1;
  uint8_t bit3                         : 1;
  uint8_t bit2                         : 1;
  uint8_t bit1                         : 1;
  uint8_t bit0                         : 1;
#endif /* DRV_BYTE_ORDER */
} bitwise_t;

#define PROPERTY_DISABLE                (0U)
#define PROPERTY_ENABLE                 (1U)

/** @addtogroup  Interfaces_Functions
  * @brief       This section provide a set of functions used to read and
  *              write a generic register of the device.
  *              MANDATORY: return 0 -> no Error.
  * @{
  *
  */

typedef int32_t (*stmdev_write_ptr)(void *, uint8_t, const uint8_t *, uint16_t);
typedef int32_t (*stmdev_read_ptr)(void *, uint8_t, uint8_t *, uint16_t);
typedef void (*stmdev_mdelay_ptr)(uint32_t millisec);

typedef struct
{
  /** Component mandatory fields **/
  stmdev_write_ptr  write_reg;
  stmdev_read_ptr   read_reg;
  /** Component optional fields **/
  stmdev_mdelay_ptr   mdelay;
  /** Customizable optional pointer **/
  void *handle;

  /** private data **/
  void *priv_data;
} stmdev_ctx_t;

/**
  * @}
  *
  */

#endif /* MEMS_SHARED_TYPES */

#ifndef MEMS_UCF_SHARED_TYPES
#define MEMS_UCF_SHARED_TYPES

/** @defgroup    Generic address-data structure definition
  * @brief       This structure is useful to load a predefined configuration
  *              of a sensor.
  *              You can create a sensor configuration by your own or using
  *              Unico / Unicleo tools available on STMicroelectronics
  *              web site.
  *
  * @{
  *
  */

typedef struct
{
  uint8_t address;
  uint8_t data;
} ucf_line_t;

/**
  * @}
  *
  */

#endif /* MEMS_UCF_SHARED_TYPES */

/**
  * @}
  *
  */

/** @defgroup LSM6DSV80X_Infos
  * @{
  *
  */

/** I2C Device Address 8 bit format  if SA0=0 -> D5 if SA0=1 -> D7 **/
#define LSM6DSV80X_I2C_ADD_L                      0xD5U
#define LSM6DSV80X_I2C_ADD_H                      0xD7U

/** Device Identification (Who am I) **/
#define LSM6DSV80X_ID                             0x73U

/**
  * @}
  *
  */

/** @defgroup bitfields page main
  * @{
  *
  */

#define LSM6DSV80X_FUNC_CFG_ACCESS                0x1U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used1                    : 2;
  uint8_t sw_por                       : 1;
  uint8_t fsm_wr_ctrl_en               : 1;
  uint8_t not_used0                    : 2;
  uint8_t shub_reg_access              : 1;
  uint8_t emb_func_reg_access          : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t emb_func_reg_access          : 1;
  uint8_t shub_reg_access              : 1;
  uint8_t not_used0                    : 2;
  uint8_t fsm_wr_ctrl_en               : 1;
  uint8_t sw_por                       : 1;
  uint8_t not_used1                    : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_func_cfg_access_t;

#define LSM6DSV80X_PIN_CTRL                       0x2U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t io_pad_strength              : 2;
  uint8_t not_used0                    : 3;
  uint8_t ibhr_por_en                  : 1;
  uint8_t sdo_pu_en                    : 1;
  uint8_t not_used1                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 1;
  uint8_t sdo_pu_en                    : 1;
  uint8_t ibhr_por_en                  : 1;
  uint8_t not_used0                    : 3;
  uint8_t io_pad_strength              : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_pin_ctrl_t;

#define LSM6DSV80X_IF_CFG                         0x3U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t i2c_i3c_disable              : 1;
  uint8_t not_used0                    : 1;
  uint8_t sim                          : 1;
  uint8_t pp_od                        : 1;
  uint8_t h_lactive                    : 1;
  uint8_t asf_ctrl                     : 1;
  uint8_t shub_pu_en                   : 1;
  uint8_t sda_pu_en                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sda_pu_en                    : 1;
  uint8_t shub_pu_en                   : 1;
  uint8_t asf_ctrl                     : 1;
  uint8_t h_lactive                    : 1;
  uint8_t pp_od                        : 1;
  uint8_t sim                          : 1;
  uint8_t not_used0                    : 1;
  uint8_t i2c_i3c_disable              : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_if_cfg_t;

#define LSM6DSV80X_ODR_TRIG_CFG                   0x6U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t odr_trig_nodr                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t odr_trig_nodr                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_odr_trig_cfg_t;

#define LSM6DSV80X_FIFO_CTRL1                     0x7U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t wtm                          : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t wtm                          : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_ctrl1_t;

#define LSM6DSV80X_FIFO_CTRL2                     0x8U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used2                    : 1;
  uint8_t uncompr_rate                 : 2;
  uint8_t not_used0                    : 1;
  uint8_t odr_chg_en                   : 1;
  uint8_t not_used1                    : 1;
  uint8_t fifo_compr_rt_en             : 1;
  uint8_t stop_on_wtm                  : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t stop_on_wtm                  : 1;
  uint8_t fifo_compr_rt_en             : 1;
  uint8_t not_used1                    : 1;
  uint8_t odr_chg_en                   : 1;
  uint8_t not_used0                    : 1;
  uint8_t uncompr_rate                 : 2;
  uint8_t not_used2                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_ctrl2_t;

#define LSM6DSV80X_FIFO_CTRL3                     0x9U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t bdr_xl                       : 4;
  uint8_t bdr_gy                       : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t bdr_gy                       : 4;
  uint8_t bdr_xl                       : 4;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_ctrl3_t;

#define LSM6DSV80X_FIFO_CTRL4                     0x0AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fifo_mode                    : 3;
  uint8_t not_used0                    : 1;
  uint8_t odr_t_batch                  : 2;
  uint8_t dec_ts_batch                 : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t dec_ts_batch                 : 2;
  uint8_t odr_t_batch                  : 2;
  uint8_t not_used0                    : 1;
  uint8_t fifo_mode                    : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_ctrl4_t;

#define LSM6DSV80X_COUNTER_BDR_REG1               0x0BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t cnt_bdr_th                   : 2;
  uint8_t not_used0                    : 1;
  uint8_t xl_hg_batch_en               : 1;
  uint8_t not_used2                    : 1;
  uint8_t trig_counter_bdr             : 2;
  uint8_t not_used1                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 1;
  uint8_t trig_counter_bdr             : 2;
  uint8_t not_used2                    : 1;
  uint8_t xl_hg_batch_en               : 1;
  uint8_t not_used0                    : 1;
  uint8_t cnt_bdr_th                   : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_counter_bdr_reg1_t;

#define LSM6DSV80X_COUNTER_BDR_REG2               0x0CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t cnt_bdr_th                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t cnt_bdr_th                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_counter_bdr_reg2_t;

#define LSM6DSV80X_INT1_CTRL                      0x0DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int1_drdy_xl                 : 1;
  uint8_t int1_drdy_g                  : 1;
  uint8_t not_used0                    : 1;
  uint8_t int1_fifo_th                 : 1;
  uint8_t int1_fifo_ovr                : 1;
  uint8_t int1_fifo_full               : 1;
  uint8_t int1_cnt_bdr                 : 1;
  uint8_t not_used1                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 1;
  uint8_t int1_cnt_bdr                 : 1;
  uint8_t int1_fifo_full               : 1;
  uint8_t int1_fifo_ovr                : 1;
  uint8_t int1_fifo_th                 : 1;
  uint8_t not_used0                    : 1;
  uint8_t int1_drdy_g                  : 1;
  uint8_t int1_drdy_xl                 : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_int1_ctrl_t;

#define LSM6DSV80X_INT2_CTRL                      0x0EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int2_drdy_xl                 : 1;
  uint8_t int2_drdy_g                  : 1;
  uint8_t not_used0                    : 1;
  uint8_t int2_fifo_th                 : 1;
  uint8_t int2_fifo_ovr                : 1;
  uint8_t int2_fifo_full               : 1;
  uint8_t int2_cnt_bdr                 : 1;
  uint8_t int2_emb_func_endop          : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int2_emb_func_endop          : 1;
  uint8_t int2_cnt_bdr                 : 1;
  uint8_t int2_fifo_full               : 1;
  uint8_t int2_fifo_ovr                : 1;
  uint8_t int2_fifo_th                 : 1;
  uint8_t not_used0                    : 1;
  uint8_t int2_drdy_g                  : 1;
  uint8_t int2_drdy_xl                 : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_int2_ctrl_t;

#define LSM6DSV80X_WHO_AM_I                       0x0FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t id                           : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t id                           : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_who_am_i_t;

#define LSM6DSV80X_CTRL1                          0x10U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t odr_xl                       : 4;
  uint8_t op_mode_xl                   : 3;
  uint8_t not_used0                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t op_mode_xl                   : 3;
  uint8_t odr_xl                       : 4;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl1_t;

#define LSM6DSV80X_CTRL2                          0x11U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t odr_g                        : 4;
  uint8_t op_mode_g                    : 3;
  uint8_t not_used0                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t op_mode_g                    : 3;
  uint8_t odr_g                        : 4;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl2_t;

#define LSM6DSV80X_CTRL3                          0x12U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sw_reset                     : 1;
  uint8_t not_used0                    : 1;
  uint8_t if_inc                       : 1;
  uint8_t not_used1                    : 3;
  uint8_t bdu                          : 1;
  uint8_t boot                         : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t boot                         : 1;
  uint8_t bdu                          : 1;
  uint8_t not_used1                    : 3;
  uint8_t if_inc                       : 1;
  uint8_t not_used0                    : 1;
  uint8_t sw_reset                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl3_t;

#define LSM6DSV80X_CTRL4                          0x13U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int2_in_lh                   : 1;
  uint8_t drdy_pulsed                  : 1;
  uint8_t int2_drdy_temp               : 1;
  uint8_t drdy_mask                    : 1;
  uint8_t int2_on_int1                 : 1;
  uint8_t not_used0                    : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 3;
  uint8_t int2_on_int1                 : 1;
  uint8_t drdy_mask                    : 1;
  uint8_t int2_drdy_temp               : 1;
  uint8_t drdy_pulsed                  : 1;
  uint8_t int2_in_lh                   : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl4_t;

#define LSM6DSV80X_CTRL5                          0x14U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int_en_i3c                   : 1;
  uint8_t bus_act_sel                  : 2;
  uint8_t not_used0                    : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 5;
  uint8_t not_used0                    : 4;
  uint8_t bus_act_sel                  : 2;
  uint8_t int_en_i3c                   : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl5_t;

#define LSM6DSV80X_CTRL6                          0x15U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fs_g                         : 3;
  uint8_t not_used1                    : 1;
  uint8_t lpf1_g_bw                    : 3;
  uint8_t not_used0                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t lpf1_g_bw                    : 3;
  uint8_t not_used1                    : 1;
  uint8_t fs_g                         : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl6_t;

#define LSM6DSV80X_CTRL7                          0x16U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t lpf1_g_en                    : 1;
  uint8_t not_used0                    : 5;
  uint8_t int2_drdy_xl_hg              : 1;
  uint8_t int1_drdy_xl_hg              : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int1_drdy_xl_hg              : 1;
  uint8_t int2_drdy_xl_hg              : 1;
  uint8_t not_used0                    : 5;
  uint8_t lpf1_g_en                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl7_t;

#define LSM6DSV80X_CTRL8                          0x17U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fs_xl                        : 2;
  uint8_t not_used0                    : 3;
  uint8_t hp_lpf2_xl_bw                : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t hp_lpf2_xl_bw                : 3;
  uint8_t not_used0                    : 3;
  uint8_t fs_xl                        : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl8_t;

#define LSM6DSV80X_CTRL9                          0x18U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t usr_off_on_out               : 1;
  uint8_t usr_off_w                    : 1;
  uint8_t not_used0                    : 1;
  uint8_t lpf2_xl_en                   : 1;
  uint8_t hp_slope_xl_en               : 1;
  uint8_t xl_fastsettl_mode            : 1;
  uint8_t hp_ref_mode_xl               : 1;
  uint8_t not_used1                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 1;
  uint8_t hp_ref_mode_xl               : 1;
  uint8_t xl_fastsettl_mode            : 1;
  uint8_t hp_slope_xl_en               : 1;
  uint8_t lpf2_xl_en                   : 1;
  uint8_t not_used0                    : 1;
  uint8_t usr_off_w                    : 1;
  uint8_t usr_off_on_out               : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl9_t;

#define LSM6DSV80X_CTRL10                         0x19U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t st_xl                        : 2;
  uint8_t st_g                         : 2;
  uint8_t not_used0                    : 2;
  uint8_t emb_func_debug               : 1;
  uint8_t not_used1                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 1;
  uint8_t emb_func_debug               : 1;
  uint8_t not_used0                    : 2;
  uint8_t st_g                         : 2;
  uint8_t st_xl                        : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl10_t;

#define LSM6DSV80X_CTRL_STATUS                    0x1AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 2;
  uint8_t fsm_wr_ctrl_status           : 1;
  uint8_t not_used1                    : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 5;
  uint8_t fsm_wr_ctrl_status           : 1;
  uint8_t not_used0                    : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl_status_t;

#define LSM6DSV80X_FIFO_STATUS1                   0x1BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t diff_fifo                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t diff_fifo                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_status1_t;

#define LSM6DSV80X_FIFO_STATUS2                   0x1CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t diff_fifo                    : 1;
  uint8_t not_used0                    : 2;
  uint8_t fifo_ovr_latched             : 1;
  uint8_t counter_bdr_ia               : 1;
  uint8_t fifo_full_ia                 : 1;
  uint8_t fifo_ovr_ia                  : 1;
  uint8_t fifo_wtm_ia                  : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fifo_wtm_ia                  : 1;
  uint8_t fifo_ovr_ia                  : 1;
  uint8_t fifo_full_ia                 : 1;
  uint8_t counter_bdr_ia               : 1;
  uint8_t fifo_ovr_latched             : 1;
  uint8_t not_used0                    : 2;
  uint8_t diff_fifo                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_status2_t;

#define LSM6DSV80X_ALL_INT_SRC                    0x1DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ff_ia                        : 1;
  uint8_t wu_ia                        : 1;
  uint8_t tap_ia                       : 1;
  uint8_t hg_ia                        : 1;
  uint8_t d6d_ia                       : 1;
  uint8_t sleep_change_ia              : 1;
  uint8_t shub_ia                      : 1;
  uint8_t emb_func_ia                  : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t emb_func_ia                  : 1;
  uint8_t shub_ia                      : 1;
  uint8_t sleep_change_ia              : 1;
  uint8_t d6d_ia                       : 1;
  uint8_t hg_ia                        : 1;
  uint8_t tap_ia                       : 1;
  uint8_t wu_ia                        : 1;
  uint8_t ff_ia                        : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_all_int_src_t;

#define LSM6DSV80X_STATUS_REG                     0x1EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xlda                         : 1;
  uint8_t gda                          : 1;
  uint8_t tda                          : 1;
  uint8_t xlhgda                       : 1;
  uint8_t not_used0                    : 3;
  uint8_t timestamp_endcount           : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t timestamp_endcount           : 1;
  uint8_t not_used0                    : 3;
  uint8_t xlhgda                       : 1;
  uint8_t tda                          : 1;
  uint8_t gda                          : 1;
  uint8_t xlda                         : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_status_reg_t;

#define LSM6DSV80X_OUT_TEMP_L                     0x20U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t temp                         : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t temp                         : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_out_temp_l_t;

#define LSM6DSV80X_OUT_TEMP_H                     0x21U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t temp                         : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t temp                         : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_out_temp_h_t;

#define LSM6DSV80X_OUTX_L_G                       0x22U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outx_g                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outx_g                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outx_l_g_t;

#define LSM6DSV80X_OUTX_H_G                       0x23U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outx_g                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outx_g                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outx_h_g_t;

#define LSM6DSV80X_OUTY_L_G                       0x24U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outy_g                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outy_g                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outy_l_g_t;

#define LSM6DSV80X_OUTY_H_G                       0x25U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outy_g                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outy_g                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outy_h_g_t;

#define LSM6DSV80X_OUTZ_L_G                       0x26U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outz_g                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outz_g                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outz_l_g_t;

#define LSM6DSV80X_OUTZ_H_G                       0x27U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outz_g                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outz_g                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outz_h_g_t;

#define LSM6DSV80X_OUTX_L_A                       0x28U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outx_a                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outx_a                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outx_l_a_t;

#define LSM6DSV80X_OUTX_H_A                       0x29U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outx_a                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outx_a                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outx_h_a_t;

#define LSM6DSV80X_OUTY_L_A                       0x2AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outy_a                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outy_a                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outy_l_a_t;

#define LSM6DSV80X_OUTY_H_A                       0x2BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outy_a                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outy_a                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outy_h_a_t;

#define LSM6DSV80X_OUTZ_L_A                       0x2CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outz_a                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outz_a                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outz_l_a_t;

#define LSM6DSV80X_OUTZ_H_A                       0x2DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t outz_a                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t outz_a                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_outz_h_a_t;

#define LSM6DSV80X_UI_OUTX_L_A_HG                 0x34U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ui_outx_a_hg                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ui_outx_a_hg                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ui_outx_l_a_hg_t;

#define LSM6DSV80X_UI_OUTX_H_A_HG                 0x35U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ui_outx_a_hg                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ui_outx_a_hg                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ui_outx_h_a_hg_t;

#define LSM6DSV80X_UI_OUTY_L_A_HG                 0x36U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ui_outy_a_hg                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ui_outy_a_hg                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ui_outy_l_a_hg_t;

#define LSM6DSV80X_UI_OUTY_H_A_HG                 0x37U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ui_outy_a_hg                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ui_outy_a_hg                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ui_outy_h_a_hg_t;

#define LSM6DSV80X_UI_OUTZ_L_A_HG                 0x38U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ui_outz_a_hg                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ui_outz_a_hg                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ui_outz_l_a_hg_t;

#define LSM6DSV80X_UI_OUTZ_H_A_HG                 0x39U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ui_outz_a_hg                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ui_outz_a_hg                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ui_outz_h_a_hg_t;

#define LSM6DSV80X_TIMESTAMP0                     0x40U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t timestamp                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t timestamp                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_timestamp0_t;

#define LSM6DSV80X_TIMESTAMP1                     0x41U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t timestamp                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t timestamp                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_timestamp1_t;

#define LSM6DSV80X_TIMESTAMP2                     0x42U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t timestamp                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t timestamp                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_timestamp2_t;

#define LSM6DSV80X_TIMESTAMP3                     0x43U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t timestamp                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t timestamp                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_timestamp3_t;

#define LSM6DSV80X_UI_STATUS_REG                  0x44U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used1                    : 2;
  uint8_t gyro_settling                : 1;
  uint8_t not_used0                    : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 5;
  uint8_t gyro_settling                : 1;
  uint8_t not_used1                    : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ui_status_reg_t;

#define LSM6DSV80X_WAKE_UP_SRC                    0x45U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t z_wu                         : 1;
  uint8_t y_wu                         : 1;
  uint8_t x_wu                         : 1;
  uint8_t wu_ia                        : 1;
  uint8_t sleep_state                  : 1;
  uint8_t ff_ia                        : 1;
  uint8_t sleep_change_ia              : 1;
  uint8_t not_used0                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t sleep_change_ia              : 1;
  uint8_t ff_ia                        : 1;
  uint8_t sleep_state                  : 1;
  uint8_t wu_ia                        : 1;
  uint8_t x_wu                         : 1;
  uint8_t y_wu                         : 1;
  uint8_t z_wu                         : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_wake_up_src_t;

#define LSM6DSV80X_TAP_SRC                        0x46U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t z_tap                        : 1;
  uint8_t y_tap                        : 1;
  uint8_t x_tap                        : 1;
  uint8_t tap_sign                     : 1;
  uint8_t double_tap                   : 1;
  uint8_t single_tap                   : 1;
  uint8_t tap_ia                       : 1;
  uint8_t not_used0                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t tap_ia                       : 1;
  uint8_t single_tap                   : 1;
  uint8_t double_tap                   : 1;
  uint8_t tap_sign                     : 1;
  uint8_t x_tap                        : 1;
  uint8_t y_tap                        : 1;
  uint8_t z_tap                        : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tap_src_t;

#define LSM6DSV80X_D6D_SRC                        0x47U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl                           : 1;
  uint8_t xh                           : 1;
  uint8_t yl                           : 1;
  uint8_t yh                           : 1;
  uint8_t zl                           : 1;
  uint8_t zh                           : 1;
  uint8_t d6d_ia                       : 1;
  uint8_t not_used0                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t d6d_ia                       : 1;
  uint8_t zh                           : 1;
  uint8_t zl                           : 1;
  uint8_t yh                           : 1;
  uint8_t yl                           : 1;
  uint8_t xh                           : 1;
  uint8_t xl                           : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_d6d_src_t;

#define LSM6DSV80X_STATUS_CONTROLLER_MAINPAGE     0x48U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sens_hub_endop               : 1;
  uint8_t not_used0                    : 2;
  uint8_t target0_nack                 : 1;
  uint8_t target1_nack                 : 1;
  uint8_t target2_nack                 : 1;
  uint8_t target3_nack                 : 1;
  uint8_t wr_once_done                 : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t wr_once_done                 : 1;
  uint8_t target3_nack                 : 1;
  uint8_t target2_nack                 : 1;
  uint8_t target1_nack                 : 1;
  uint8_t target0_nack                 : 1;
  uint8_t not_used0                    : 2;
  uint8_t sens_hub_endop               : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_status_controller_mainpage_t;

#define LSM6DSV80X_EMB_FUNC_STATUS_MAINPAGE       0x49U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 3;
  uint8_t is_step_det                  : 1;
  uint8_t is_tilt                      : 1;
  uint8_t is_sigmot                    : 1;
  uint8_t not_used1                    : 1;
  uint8_t is_fsm_lc                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t is_fsm_lc                    : 1;
  uint8_t not_used1                    : 1;
  uint8_t is_sigmot                    : 1;
  uint8_t is_tilt                      : 1;
  uint8_t is_step_det                  : 1;
  uint8_t not_used0                    : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_status_mainpage_t;

#define LSM6DSV80X_FSM_STATUS_MAINPAGE            0x4AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t is_fsm1                      : 1;
  uint8_t is_fsm2                      : 1;
  uint8_t is_fsm3                      : 1;
  uint8_t is_fsm4                      : 1;
  uint8_t is_fsm5                      : 1;
  uint8_t is_fsm6                      : 1;
  uint8_t is_fsm7                      : 1;
  uint8_t is_fsm8                      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t is_fsm8                      : 1;
  uint8_t is_fsm7                      : 1;
  uint8_t is_fsm6                      : 1;
  uint8_t is_fsm5                      : 1;
  uint8_t is_fsm4                      : 1;
  uint8_t is_fsm3                      : 1;
  uint8_t is_fsm2                      : 1;
  uint8_t is_fsm1                      : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_status_mainpage_t;

#define LSM6DSV80X_MLC_STATUS_MAINPAGE            0x4BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t is_mlc1                      : 1;
  uint8_t is_mlc2                      : 1;
  uint8_t is_mlc3                      : 1;
  uint8_t is_mlc4                      : 1;
  uint8_t is_mlc5                      : 1;
  uint8_t is_mlc6                      : 1;
  uint8_t is_mlc7                      : 1;
  uint8_t is_mlc8                      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t is_mlc8                      : 1;
  uint8_t is_mlc7                      : 1;
  uint8_t is_mlc6                      : 1;
  uint8_t is_mlc5                      : 1;
  uint8_t is_mlc4                      : 1;
  uint8_t is_mlc3                      : 1;
  uint8_t is_mlc2                      : 1;
  uint8_t is_mlc1                      : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc_status_mainpage_t;

#define LSM6DSV80X_HG_WAKE_UP_SRC                 0x4CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t hg_z_wu                      : 1;
  uint8_t hg_y_wu                      : 1;
  uint8_t hg_x_wu                      : 1;
  uint8_t hg_wu_ia                     : 1;
  uint8_t hg_wu_change_ia              : 1;
  uint8_t hg_shock_state               : 1;
  uint8_t hg_shock_change_ia           : 1;
  uint8_t not_used0                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t hg_shock_change_ia           : 1;
  uint8_t hg_shock_state               : 1;
  uint8_t hg_wu_change_ia              : 1;
  uint8_t hg_wu_ia                     : 1;
  uint8_t hg_x_wu                      : 1;
  uint8_t hg_y_wu                      : 1;
  uint8_t hg_z_wu                      : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_hg_wake_up_src_t;

#define LSM6DSV80X_CTRL2_XL_HG                    0x4DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl_hg_st                     : 2;
  uint8_t not_used0                    : 2;
  uint8_t hg_usr_off_on_wu             : 1;
  uint8_t not_used1                    : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 3;
  uint8_t hg_usr_off_on_wu             : 1;
  uint8_t not_used0                    : 2;
  uint8_t xl_hg_st                     : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl2_xl_hg_t;

#define LSM6DSV80X_CTRL1_XL_HG                    0x4EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fs_xl_hg                     : 3;
  uint8_t odr_xl_hg                    : 3;
  uint8_t hg_usr_off_on_out            : 1;
  uint8_t xl_hg_regout_en              : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t xl_hg_regout_en              : 1;
  uint8_t hg_usr_off_on_out            : 1;
  uint8_t odr_xl_hg                    : 3;
  uint8_t fs_xl_hg                     : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ctrl1_xl_hg_t;

#define LSM6DSV80X_INTERNAL_FREQ                  0x4FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t freq_fine                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t freq_fine                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_internal_freq_t;

#define LSM6DSV80X_FUNCTIONS_ENABLE               0x50U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t inact_en                     : 2;
  uint8_t not_used0                    : 1;
  uint8_t dis_rst_lir_all_int          : 1;
  uint8_t not_used1                    : 2;
  uint8_t timestamp_en                 : 1;
  uint8_t interrupts_enable            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t interrupts_enable            : 1;
  uint8_t timestamp_en                 : 1;
  uint8_t not_used1                    : 2;
  uint8_t dis_rst_lir_all_int          : 1;
  uint8_t not_used0                    : 1;
  uint8_t inact_en                     : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_functions_enable_t;

#define LSM6DSV80X_HG_FUNCTIONS_ENABLE            0x52U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t hg_shock_dur                 : 4;
  uint8_t int1_hg_wu                   : 1;
  uint8_t int2_hg_wu                   : 1;
  uint8_t hg_wu_change_int_sel         : 1;
  uint8_t hg_interrupts_enable         : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t hg_interrupts_enable         : 1;
  uint8_t hg_wu_change_int_sel         : 1;
  uint8_t int2_hg_wu                   : 1;
  uint8_t int1_hg_wu                   : 1;
  uint8_t hg_shock_dur                 : 4;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_hg_functions_enable_t;

#define LSM6DSV80X_HG_WAKE_UP_THS                 0x53U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t hg_wk_ths                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t hg_wk_ths                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_hg_wake_up_ths_t;

#define LSM6DSV80X_INACTIVITY_DUR                 0x54U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t inact_dur                    : 2;
  uint8_t xl_inact_odr                 : 2;
  uint8_t wu_inact_ths_w               : 3;
  uint8_t sleep_status_on_int          : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sleep_status_on_int          : 1;
  uint8_t wu_inact_ths_w               : 3;
  uint8_t xl_inact_odr                 : 2;
  uint8_t inact_dur                    : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_inactivity_dur_t;

#define LSM6DSV80X_INACTIVITY_THS                 0x55U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t inact_ths                    : 6;
  uint8_t int1_hg_shock_change         : 1;
  uint8_t int2_hg_shock_change         : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int2_hg_shock_change         : 1;
  uint8_t int1_hg_shock_change         : 1;
  uint8_t inact_ths                    : 6;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_inactivity_ths_t;

#define LSM6DSV80X_TAP_CFG0                       0x56U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t lir                          : 1;
  uint8_t tap_z_en                     : 1;
  uint8_t tap_y_en                     : 1;
  uint8_t tap_x_en                     : 1;
  uint8_t slope_fds                    : 1;
  uint8_t hw_func_mask_xl_settl        : 1;
  uint8_t low_pass_on_6d               : 1;
  uint8_t not_used1                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 1;
  uint8_t low_pass_on_6d               : 1;
  uint8_t hw_func_mask_xl_settl        : 1;
  uint8_t slope_fds                    : 1;
  uint8_t tap_x_en                     : 1;
  uint8_t tap_y_en                     : 1;
  uint8_t tap_z_en                     : 1;
  uint8_t lir                          : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tap_cfg0_t;

#define LSM6DSV80X_TAP_CFG1                       0x57U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t tap_ths_x                    : 5;
  uint8_t tap_priority                 : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t tap_priority                 : 3;
  uint8_t tap_ths_x                    : 5;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tap_cfg1_t;

#define LSM6DSV80X_TAP_CFG2                       0x58U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t tap_ths_y                    : 5;
  uint8_t not_used0                    : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 3;
  uint8_t tap_ths_y                    : 5;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tap_cfg2_t;

#define LSM6DSV80X_TAP_THS_6D                     0x59U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t tap_ths_z                    : 5;
  uint8_t sixd_ths                     : 2;
  uint8_t d4d_en                       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t d4d_en                       : 1;
  uint8_t sixd_ths                     : 2;
  uint8_t tap_ths_z                    : 5;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tap_ths_6d_t;

#define LSM6DSV80X_TAP_DUR                        0x5AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t shock                        : 2;
  uint8_t quiet                        : 2;
  uint8_t dur                          : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t dur                          : 4;
  uint8_t quiet                        : 2;
  uint8_t shock                        : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tap_dur_t;

#define LSM6DSV80X_WAKE_UP_THS                    0x5BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t wk_ths                       : 6;
  uint8_t usr_off_on_wu                : 1;
  uint8_t single_double_tap            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t single_double_tap            : 1;
  uint8_t usr_off_on_wu                : 1;
  uint8_t wk_ths                       : 6;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_wake_up_ths_t;

#define LSM6DSV80X_WAKE_UP_DUR                    0x5CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sleep_dur                    : 4;
  uint8_t not_used0                    : 1;
  uint8_t wake_dur                     : 2;
  uint8_t ff_dur                       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ff_dur                       : 1;
  uint8_t wake_dur                     : 2;
  uint8_t not_used0                    : 1;
  uint8_t sleep_dur                    : 4;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_wake_up_dur_t;

#define LSM6DSV80X_FREE_FALL                      0x5DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ff_ths                       : 3;
  uint8_t ff_dur                       : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ff_dur                       : 5;
  uint8_t ff_ths                       : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_free_fall_t;

#define LSM6DSV80X_MD1_CFG                        0x5EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int1_shub                    : 1;
  uint8_t int1_emb_func                : 1;
  uint8_t int1_6d                      : 1;
  uint8_t int1_double_tap              : 1;
  uint8_t int1_ff                      : 1;
  uint8_t int1_wu                      : 1;
  uint8_t int1_single_tap              : 1;
  uint8_t int1_sleep_change            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int1_sleep_change            : 1;
  uint8_t int1_single_tap              : 1;
  uint8_t int1_wu                      : 1;
  uint8_t int1_ff                      : 1;
  uint8_t int1_double_tap              : 1;
  uint8_t int1_6d                      : 1;
  uint8_t int1_emb_func                : 1;
  uint8_t int1_shub                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_md1_cfg_t;

#define LSM6DSV80X_MD2_CFG                        0x5FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int2_timestamp               : 1;
  uint8_t int2_emb_func                : 1;
  uint8_t int2_6d                      : 1;
  uint8_t int2_double_tap              : 1;
  uint8_t int2_ff                      : 1;
  uint8_t int2_wu                      : 1;
  uint8_t int2_single_tap              : 1;
  uint8_t int2_sleep_change            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int2_sleep_change            : 1;
  uint8_t int2_single_tap              : 1;
  uint8_t int2_wu                      : 1;
  uint8_t int2_ff                      : 1;
  uint8_t int2_double_tap              : 1;
  uint8_t int2_6d                      : 1;
  uint8_t int2_emb_func                : 1;
  uint8_t int2_timestamp               : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_md2_cfg_t;

#define LSM6DSV80X_HAODR_CFG                      0x62U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t haodr_sel                    : 2;
  uint8_t not_used0                    : 6;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 6;
  uint8_t haodr_sel                    : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_haodr_cfg_t;

#define LSM6DSV80X_EMB_FUNC_CFG                   0x63U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 3;
  uint8_t emb_func_disable             : 1;
  uint8_t emb_func_irq_mask_xl_settl   : 1;
  uint8_t emb_func_irq_mask_g_settl    : 1;
  uint8_t emb_func_irq_mask_xl_hg_settl: 1;
  uint8_t hg_usr_off_on_emb_func       : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t hg_usr_off_on_emb_func       : 1;
  uint8_t emb_func_irq_mask_xl_hg_settl: 1;
  uint8_t emb_func_irq_mask_g_settl    : 1;
  uint8_t emb_func_irq_mask_xl_settl   : 1;
  uint8_t emb_func_disable             : 1;
  uint8_t not_used0                    : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_cfg_t;

#define LSM6DSV80X_XL_HG_X_OFS_USR                0x6CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl_hg_x_ofs_usr              : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t xl_hg_x_ofs_usr              : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_hg_x_ofs_usr_t;

#define LSM6DSV80X_XL_HG_Y_OFS_USR                0x6DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl_hg_y_ofs_usr              : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t xl_hg_y_ofs_usr              : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_hg_y_ofs_usr_t;

#define LSM6DSV80X_XL_HG_Z_OFS_USR                0x6EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl_hg_z_ofs_usr              : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t xl_hg_z_ofs_usr              : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_hg_z_ofs_usr_t;

#define LSM6DSV80X_X_OFS_USR                      0x73U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t x_ofs_usr                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t x_ofs_usr                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_x_ofs_usr_t;

#define LSM6DSV80X_Y_OFS_USR                      0x74U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t y_ofs_usr                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t y_ofs_usr                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_y_ofs_usr_t;

#define LSM6DSV80X_Z_OFS_USR                      0x75U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t z_ofs_usr                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t z_ofs_usr                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_z_ofs_usr_t;

#define LSM6DSV80X_FIFO_DATA_OUT_TAG              0x78U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t tag_cnt                      : 2;
  uint8_t tag_sensor                   : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t tag_sensor                   : 5;
  uint8_t tag_cnt                      : 2;
  uint8_t not_used0                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_data_out_tag_t;

#define LSM6DSV80X_FIFO_DATA_OUT_X_L              0x79U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fifo_data_out                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fifo_data_out                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_data_out_x_l_t;

#define LSM6DSV80X_FIFO_DATA_OUT_X_H              0x7AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fifo_data_out                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fifo_data_out                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_data_out_x_h_t;

#define LSM6DSV80X_FIFO_DATA_OUT_Y_L              0x7BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fifo_data_out                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fifo_data_out                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_data_out_y_l_t;

#define LSM6DSV80X_FIFO_DATA_OUT_Y_H              0x7CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fifo_data_out                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fifo_data_out                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_data_out_y_h_t;

#define LSM6DSV80X_FIFO_DATA_OUT_Z_L              0x7DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fifo_data_out                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fifo_data_out                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_data_out_z_l_t;

#define LSM6DSV80X_FIFO_DATA_OUT_Z_H              0x7EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fifo_data_out                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fifo_data_out                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fifo_data_out_z_h_t;

/**
  * @}
  *
  */

/** @defgroup bitfields page embedded
  * @{
  *
  */

#define LSM6DSV80X_PAGE_SEL                       0x2U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 4;
  uint8_t page_sel                     : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t page_sel                     : 4;
  uint8_t not_used0                    : 4;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_page_sel_t;

#define LSM6DSV80X_EMB_FUNC_EN_A                  0x4U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t sflp_game_en                 : 1;
  uint8_t not_used2                    : 1;
  uint8_t pedo_en                      : 1;
  uint8_t tilt_en                      : 1;
  uint8_t sign_motion_en               : 1;
  uint8_t not_used1                    : 1;
  uint8_t mlc_before_fsm_en            : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc_before_fsm_en            : 1;
  uint8_t not_used1                    : 1;
  uint8_t sign_motion_en               : 1;
  uint8_t tilt_en                      : 1;
  uint8_t pedo_en                      : 1;
  uint8_t not_used2                    : 1;
  uint8_t sflp_game_en                 : 1;
  uint8_t not_used0                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_en_a_t;

#define LSM6DSV80X_EMB_FUNC_EN_B                  0x5U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_en                       : 1;
  uint8_t not_used0                    : 2;
  uint8_t fifo_compr_en                : 1;
  uint8_t mlc_en                       : 1;
  uint8_t not_used1                    : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 3;
  uint8_t mlc_en                       : 1;
  uint8_t fifo_compr_en                : 1;
  uint8_t not_used0                    : 2;
  uint8_t fsm_en                       : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_en_b_t;

#define LSM6DSV80X_EMB_FUNC_EXEC_STATUS           0x7U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t emb_func_endop               : 1;
  uint8_t emb_func_exec_ovr            : 1;
  uint8_t not_used0                    : 6;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 6;
  uint8_t emb_func_exec_ovr            : 1;
  uint8_t emb_func_endop               : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_exec_status_t;

#define LSM6DSV80X_PAGE_ADDRESS                   0x8U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t page_addr                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t page_addr                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_page_address_t;

#define LSM6DSV80X_PAGE_VALUE                     0x9U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t page_value                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t page_value                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_page_value_t;

#define LSM6DSV80X_EMB_FUNC_INT1                  0x0AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 3;
  uint8_t int1_step_detector           : 1;
  uint8_t int1_tilt                    : 1;
  uint8_t int1_sig_mot                 : 1;
  uint8_t not_used1                    : 1;
  uint8_t int1_fsm_lc                  : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int1_fsm_lc                  : 1;
  uint8_t not_used1                    : 1;
  uint8_t int1_sig_mot                 : 1;
  uint8_t int1_tilt                    : 1;
  uint8_t int1_step_detector           : 1;
  uint8_t not_used0                    : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_int1_t;

#define LSM6DSV80X_FSM_INT1                       0x0BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int1_fsm1                    : 1;
  uint8_t int1_fsm2                    : 1;
  uint8_t int1_fsm3                    : 1;
  uint8_t int1_fsm4                    : 1;
  uint8_t int1_fsm5                    : 1;
  uint8_t int1_fsm6                    : 1;
  uint8_t int1_fsm7                    : 1;
  uint8_t int1_fsm8                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int1_fsm8                    : 1;
  uint8_t int1_fsm7                    : 1;
  uint8_t int1_fsm6                    : 1;
  uint8_t int1_fsm5                    : 1;
  uint8_t int1_fsm4                    : 1;
  uint8_t int1_fsm3                    : 1;
  uint8_t int1_fsm2                    : 1;
  uint8_t int1_fsm1                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_int1_t;

#define LSM6DSV80X_MLC_INT1                       0x0DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int1_mlc1                    : 1;
  uint8_t int1_mlc2                    : 1;
  uint8_t int1_mlc3                    : 1;
  uint8_t int1_mlc4                    : 1;
  uint8_t int1_mlc5                    : 1;
  uint8_t int1_mlc6                    : 1;
  uint8_t int1_mlc7                    : 1;
  uint8_t int1_mlc8                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int1_mlc8                    : 1;
  uint8_t int1_mlc7                    : 1;
  uint8_t int1_mlc6                    : 1;
  uint8_t int1_mlc5                    : 1;
  uint8_t int1_mlc4                    : 1;
  uint8_t int1_mlc3                    : 1;
  uint8_t int1_mlc2                    : 1;
  uint8_t int1_mlc1                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc_int1_t;

#define LSM6DSV80X_EMB_FUNC_INT2                  0x0EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 3;
  uint8_t int2_step_detector           : 1;
  uint8_t int2_tilt                    : 1;
  uint8_t int2_sig_mot                 : 1;
  uint8_t not_used1                    : 1;
  uint8_t int2_fsm_lc                  : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int2_fsm_lc                  : 1;
  uint8_t not_used1                    : 1;
  uint8_t int2_sig_mot                 : 1;
  uint8_t int2_tilt                    : 1;
  uint8_t int2_step_detector           : 1;
  uint8_t not_used0                    : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_int2_t;

#define LSM6DSV80X_FSM_INT2                       0x0FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int2_fsm1                    : 1;
  uint8_t int2_fsm2                    : 1;
  uint8_t int2_fsm3                    : 1;
  uint8_t int2_fsm4                    : 1;
  uint8_t int2_fsm5                    : 1;
  uint8_t int2_fsm6                    : 1;
  uint8_t int2_fsm7                    : 1;
  uint8_t int2_fsm8                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int2_fsm8                    : 1;
  uint8_t int2_fsm7                    : 1;
  uint8_t int2_fsm6                    : 1;
  uint8_t int2_fsm5                    : 1;
  uint8_t int2_fsm4                    : 1;
  uint8_t int2_fsm3                    : 1;
  uint8_t int2_fsm2                    : 1;
  uint8_t int2_fsm1                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_int2_t;

#define LSM6DSV80X_MLC_INT2                       0x11U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t int2_mlc1                    : 1;
  uint8_t int2_mlc2                    : 1;
  uint8_t int2_mlc3                    : 1;
  uint8_t int2_mlc4                    : 1;
  uint8_t int2_mlc5                    : 1;
  uint8_t int2_mlc6                    : 1;
  uint8_t int2_mlc7                    : 1;
  uint8_t int2_mlc8                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t int2_mlc8                    : 1;
  uint8_t int2_mlc7                    : 1;
  uint8_t int2_mlc6                    : 1;
  uint8_t int2_mlc5                    : 1;
  uint8_t int2_mlc4                    : 1;
  uint8_t int2_mlc3                    : 1;
  uint8_t int2_mlc2                    : 1;
  uint8_t int2_mlc1                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc_int2_t;

#define LSM6DSV80X_EMB_FUNC_STATUS                0x12U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 3;
  uint8_t is_step_det                  : 1;
  uint8_t is_tilt                      : 1;
  uint8_t is_sigmot                    : 1;
  uint8_t not_used1                    : 1;
  uint8_t is_fsm_lc                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t is_fsm_lc                    : 1;
  uint8_t not_used1                    : 1;
  uint8_t is_sigmot                    : 1;
  uint8_t is_tilt                      : 1;
  uint8_t is_step_det                  : 1;
  uint8_t not_used0                    : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_status_t;

#define LSM6DSV80X_FSM_STATUS                     0x13U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t is_fsm1                      : 1;
  uint8_t is_fsm2                      : 1;
  uint8_t is_fsm3                      : 1;
  uint8_t is_fsm4                      : 1;
  uint8_t is_fsm5                      : 1;
  uint8_t is_fsm6                      : 1;
  uint8_t is_fsm7                      : 1;
  uint8_t is_fsm8                      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t is_fsm8                      : 1;
  uint8_t is_fsm7                      : 1;
  uint8_t is_fsm6                      : 1;
  uint8_t is_fsm5                      : 1;
  uint8_t is_fsm4                      : 1;
  uint8_t is_fsm3                      : 1;
  uint8_t is_fsm2                      : 1;
  uint8_t is_fsm1                      : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_status_t;

#define LSM6DSV80X_MLC_STATUS                     0x15U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t is_mlc1                      : 1;
  uint8_t is_mlc2                      : 1;
  uint8_t is_mlc3                      : 1;
  uint8_t is_mlc4                      : 1;
  uint8_t is_mlc5                      : 1;
  uint8_t is_mlc6                      : 1;
  uint8_t is_mlc7                      : 1;
  uint8_t is_mlc8                      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t is_mlc8                      : 1;
  uint8_t is_mlc7                      : 1;
  uint8_t is_mlc6                      : 1;
  uint8_t is_mlc5                      : 1;
  uint8_t is_mlc4                      : 1;
  uint8_t is_mlc3                      : 1;
  uint8_t is_mlc2                      : 1;
  uint8_t is_mlc1                      : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc_status_t;

#define LSM6DSV80X_PAGE_RW                        0x17U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 5;
  uint8_t page_read                    : 1;
  uint8_t page_write                   : 1;
  uint8_t emb_func_lir                 : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t emb_func_lir                 : 1;
  uint8_t page_write                   : 1;
  uint8_t page_read                    : 1;
  uint8_t not_used0                    : 5;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_page_rw_t;

#define LSM6DSV80X_SFLP_GBIASX_L                  0x18U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasx                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasx                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasx_l_t;

#define LSM6DSV80X_SFLP_GBIASX_H                  0x19U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasx                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasx                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasx_h_t;

#define LSM6DSV80X_SFLP_GBIASY_L                  0x1AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasy                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasy                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasy_l_t;

#define LSM6DSV80X_SFLP_GBIASY_H                  0x1BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasy                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasy                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasy_h_t;

#define LSM6DSV80X_SFLP_GBIASZ_L                  0x1CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasz                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasz                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasz_l_t;

#define LSM6DSV80X_SFLP_GBIASZ_H                  0x1DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasz                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasz                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasz_h_t;

#define LSM6DSV80X_SFLP_GRAVX_L                   0x1EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gravx                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gravx                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gravx_l_t;

#define LSM6DSV80X_SFLP_GRAVX_H                   0x1FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gravx                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gravx                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gravx_h_t;

#define LSM6DSV80X_SFLP_GRAVY_L                   0x20U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gravy                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gravy                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gravy_l_t;

#define LSM6DSV80X_SFLP_GRAVY_H                   0x21U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gravy                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gravy                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gravy_h_t;

#define LSM6DSV80X_SFLP_GRAVZ_L                   0x22U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gravz                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gravz                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gravz_l_t;

#define LSM6DSV80X_SFLP_GRAVZ_H                   0x23U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gravz                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gravz                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gravz_h_t;

#define LSM6DSV80X_SFLP_QUATW_L                   0x2AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_quatw                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_quatw                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_quatw_l_t;

#define LSM6DSV80X_SFLP_QUATW_H                   0x2BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_quatw                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_quatw                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_quatw_h_t;

#define LSM6DSV80X_SFLP_QUATX_L                   0x2CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_quatx                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_quatx                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_quatx_l_t;

#define LSM6DSV80X_SFLP_QUATX_H                   0x2DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_quatx                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_quatx                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_quatx_h_t;

#define LSM6DSV80X_SFLP_QUATY_L                   0x2EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_quaty                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_quaty                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_quaty_l_t;

#define LSM6DSV80X_SFLP_QUATY_H                   0x2FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_quaty                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_quaty                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_quaty_h_t;

#define LSM6DSV80X_SFLP_QUATZ_L                   0x30U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_quatz                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_quatz                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_quatz_l_t;

#define LSM6DSV80X_SFLP_QUATZ_H                   0x31U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_quatz                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_quatz                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_quatz_h_t;

#define LSM6DSV80X_SFLP_GBIASX_INIT_L             0x32U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasx_init             : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasx_init             : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasx_init_l_t;

#define LSM6DSV80X_SFLP_GBIASX_INIT_H             0x33U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasx_init             : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasx_init             : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasx_init_h_t;

#define LSM6DSV80X_SFLP_GBIASY_INIT_L             0x34U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasy_init             : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasy_init             : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasy_init_l_t;

#define LSM6DSV80X_SFLP_GBIASY_INIT_H             0x35U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasy_init             : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasy_init             : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasy_init_h_t;

#define LSM6DSV80X_SFLP_GBIASZ_INIT_L             0x36U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasz_init             : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasz_init             : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasz_init_l_t;

#define LSM6DSV80X_SFLP_GBIASZ_INIT_H             0x37U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sflp_gbiasz_init             : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sflp_gbiasz_init             : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_gbiasz_init_h_t;

#define LSM6DSV80X_EMB_FUNC_FIFO_EN_A             0x44U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t sflp_game_fifo_en            : 1;
  uint8_t not_used1                    : 2;
  uint8_t sflp_gravity_fifo_en         : 1;
  uint8_t sflp_gbias_fifo_en           : 1;
  uint8_t step_counter_fifo_en         : 1;
  uint8_t mlc_fifo_en                  : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc_fifo_en                  : 1;
  uint8_t step_counter_fifo_en         : 1;
  uint8_t sflp_gbias_fifo_en           : 1;
  uint8_t sflp_gravity_fifo_en         : 1;
  uint8_t not_used1                    : 2;
  uint8_t sflp_game_fifo_en            : 1;
  uint8_t not_used0                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_fifo_en_a_t;

#define LSM6DSV80X_EMB_FUNC_FIFO_EN_B             0x45U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t mlc_filter_feature_fifo_en   : 1;
  uint8_t fsm_fifo_en                  : 1;
  uint8_t not_used1                    : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 5;
  uint8_t fsm_fifo_en                  : 1;
  uint8_t mlc_filter_feature_fifo_en   : 1;
  uint8_t not_used0                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_fifo_en_b_t;

#define LSM6DSV80X_FSM_ENABLE                     0x46U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm1_en                      : 1;
  uint8_t fsm2_en                      : 1;
  uint8_t fsm3_en                      : 1;
  uint8_t fsm4_en                      : 1;
  uint8_t fsm5_en                      : 1;
  uint8_t fsm6_en                      : 1;
  uint8_t fsm7_en                      : 1;
  uint8_t fsm8_en                      : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm8_en                      : 1;
  uint8_t fsm7_en                      : 1;
  uint8_t fsm6_en                      : 1;
  uint8_t fsm5_en                      : 1;
  uint8_t fsm4_en                      : 1;
  uint8_t fsm3_en                      : 1;
  uint8_t fsm2_en                      : 1;
  uint8_t fsm1_en                      : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_enable_t;

#define LSM6DSV80X_FSM_LONG_COUNTER_L             0x48U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_lc                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_lc                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_long_counter_l_t;

#define LSM6DSV80X_FSM_LONG_COUNTER_H             0x49U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_lc                       : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_lc                       : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_long_counter_h_t;

#define LSM6DSV80X_INT_ACK_MASK                   0x4BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t iack_mask                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t iack_mask                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_int_ack_mask_t;

#define LSM6DSV80X_FSM_OUTS1                      0x4CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm1_n_v                     : 1;
  uint8_t fsm1_p_v                     : 1;
  uint8_t fsm1_n_z                     : 1;
  uint8_t fsm1_p_z                     : 1;
  uint8_t fsm1_n_y                     : 1;
  uint8_t fsm1_p_y                     : 1;
  uint8_t fsm1_n_x                     : 1;
  uint8_t fsm1_p_x                     : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm1_p_x                     : 1;
  uint8_t fsm1_n_x                     : 1;
  uint8_t fsm1_p_y                     : 1;
  uint8_t fsm1_n_y                     : 1;
  uint8_t fsm1_p_z                     : 1;
  uint8_t fsm1_n_z                     : 1;
  uint8_t fsm1_p_v                     : 1;
  uint8_t fsm1_n_v                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_outs1_t;

#define LSM6DSV80X_FSM_OUTS2                      0x4DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm2_n_v                     : 1;
  uint8_t fsm2_p_v                     : 1;
  uint8_t fsm2_n_z                     : 1;
  uint8_t fsm2_p_z                     : 1;
  uint8_t fsm2_n_y                     : 1;
  uint8_t fsm2_p_y                     : 1;
  uint8_t fsm2_n_x                     : 1;
  uint8_t fsm2_p_x                     : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm2_p_x                     : 1;
  uint8_t fsm2_n_x                     : 1;
  uint8_t fsm2_p_y                     : 1;
  uint8_t fsm2_n_y                     : 1;
  uint8_t fsm2_p_z                     : 1;
  uint8_t fsm2_n_z                     : 1;
  uint8_t fsm2_p_v                     : 1;
  uint8_t fsm2_n_v                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_outs2_t;

#define LSM6DSV80X_FSM_OUTS3                      0x4EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm3_n_v                     : 1;
  uint8_t fsm3_p_v                     : 1;
  uint8_t fsm3_n_z                     : 1;
  uint8_t fsm3_p_z                     : 1;
  uint8_t fsm3_n_y                     : 1;
  uint8_t fsm3_p_y                     : 1;
  uint8_t fsm3_n_x                     : 1;
  uint8_t fsm3_p_x                     : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm3_p_x                     : 1;
  uint8_t fsm3_n_x                     : 1;
  uint8_t fsm3_p_y                     : 1;
  uint8_t fsm3_n_y                     : 1;
  uint8_t fsm3_p_z                     : 1;
  uint8_t fsm3_n_z                     : 1;
  uint8_t fsm3_p_v                     : 1;
  uint8_t fsm3_n_v                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_outs3_t;

#define LSM6DSV80X_FSM_OUTS4                      0x4FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm4_n_v                     : 1;
  uint8_t fsm4_p_v                     : 1;
  uint8_t fsm4_n_z                     : 1;
  uint8_t fsm4_p_z                     : 1;
  uint8_t fsm4_n_y                     : 1;
  uint8_t fsm4_p_y                     : 1;
  uint8_t fsm4_n_x                     : 1;
  uint8_t fsm4_p_x                     : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm4_p_x                     : 1;
  uint8_t fsm4_n_x                     : 1;
  uint8_t fsm4_p_y                     : 1;
  uint8_t fsm4_n_y                     : 1;
  uint8_t fsm4_p_z                     : 1;
  uint8_t fsm4_n_z                     : 1;
  uint8_t fsm4_p_v                     : 1;
  uint8_t fsm4_n_v                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_outs4_t;

#define LSM6DSV80X_FSM_OUTS5                      0x50U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm5_n_v                     : 1;
  uint8_t fsm5_p_v                     : 1;
  uint8_t fsm5_n_z                     : 1;
  uint8_t fsm5_p_z                     : 1;
  uint8_t fsm5_n_y                     : 1;
  uint8_t fsm5_p_y                     : 1;
  uint8_t fsm5_n_x                     : 1;
  uint8_t fsm5_p_x                     : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm5_p_x                     : 1;
  uint8_t fsm5_n_x                     : 1;
  uint8_t fsm5_p_y                     : 1;
  uint8_t fsm5_n_y                     : 1;
  uint8_t fsm5_p_z                     : 1;
  uint8_t fsm5_n_z                     : 1;
  uint8_t fsm5_p_v                     : 1;
  uint8_t fsm5_n_v                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_outs5_t;

#define LSM6DSV80X_FSM_OUTS6                      0x51U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm6_n_v                     : 1;
  uint8_t fsm6_p_v                     : 1;
  uint8_t fsm6_n_z                     : 1;
  uint8_t fsm6_p_z                     : 1;
  uint8_t fsm6_n_y                     : 1;
  uint8_t fsm6_p_y                     : 1;
  uint8_t fsm6_n_x                     : 1;
  uint8_t fsm6_p_x                     : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm6_p_x                     : 1;
  uint8_t fsm6_n_x                     : 1;
  uint8_t fsm6_p_y                     : 1;
  uint8_t fsm6_n_y                     : 1;
  uint8_t fsm6_p_z                     : 1;
  uint8_t fsm6_n_z                     : 1;
  uint8_t fsm6_p_v                     : 1;
  uint8_t fsm6_n_v                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_outs6_t;

#define LSM6DSV80X_FSM_OUTS7                      0x52U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm7_n_v                     : 1;
  uint8_t fsm7_p_v                     : 1;
  uint8_t fsm7_n_z                     : 1;
  uint8_t fsm7_p_z                     : 1;
  uint8_t fsm7_n_y                     : 1;
  uint8_t fsm7_p_y                     : 1;
  uint8_t fsm7_n_x                     : 1;
  uint8_t fsm7_p_x                     : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm7_p_x                     : 1;
  uint8_t fsm7_n_x                     : 1;
  uint8_t fsm7_p_y                     : 1;
  uint8_t fsm7_n_y                     : 1;
  uint8_t fsm7_p_z                     : 1;
  uint8_t fsm7_n_z                     : 1;
  uint8_t fsm7_p_v                     : 1;
  uint8_t fsm7_n_v                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_outs7_t;

#define LSM6DSV80X_FSM_OUTS8                      0x53U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm8_n_v                     : 1;
  uint8_t fsm8_p_v                     : 1;
  uint8_t fsm8_n_z                     : 1;
  uint8_t fsm8_p_z                     : 1;
  uint8_t fsm8_n_y                     : 1;
  uint8_t fsm8_p_y                     : 1;
  uint8_t fsm8_n_x                     : 1;
  uint8_t fsm8_p_x                     : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm8_p_x                     : 1;
  uint8_t fsm8_n_x                     : 1;
  uint8_t fsm8_p_y                     : 1;
  uint8_t fsm8_n_y                     : 1;
  uint8_t fsm8_p_z                     : 1;
  uint8_t fsm8_n_z                     : 1;
  uint8_t fsm8_p_v                     : 1;
  uint8_t fsm8_n_v                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_outs8_t;

#define LSM6DSV80X_SFLP_ODR                       0x5EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 3;
  uint8_t sflp_game_odr                : 3;
  uint8_t not_used1                    : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 2;
  uint8_t sflp_game_odr                : 3;
  uint8_t not_used0                    : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sflp_odr_t;

#define LSM6DSV80X_FSM_ODR                        0x5FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 3;
  uint8_t fsm_odr                      : 3;
  uint8_t not_used1                    : 2;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 2;
  uint8_t fsm_odr                      : 3;
  uint8_t not_used0                    : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_odr_t;

#define LSM6DSV80X_MLC_ODR                        0x60U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 4;
  uint8_t mlc_odr                      : 3;
  uint8_t not_used1                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 1;
  uint8_t mlc_odr                      : 3;
  uint8_t not_used0                    : 4;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc_odr_t;

#define LSM6DSV80X_STEP_COUNTER_L                 0x62U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t step                         : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t step                         : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_step_counter_l_t;

#define LSM6DSV80X_STEP_COUNTER_H                 0x63U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t step                         : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t step                         : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_step_counter_h_t;

#define LSM6DSV80X_EMB_FUNC_SRC                   0x64U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 2;
  uint8_t stepcounter_bit_set          : 1;
  uint8_t step_overflow                : 1;
  uint8_t step_count_delta_ia          : 1;
  uint8_t step_detected                : 1;
  uint8_t not_used1                    : 1;
  uint8_t pedo_rst_step                : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t pedo_rst_step                : 1;
  uint8_t not_used1                    : 1;
  uint8_t step_detected                : 1;
  uint8_t step_count_delta_ia          : 1;
  uint8_t step_overflow                : 1;
  uint8_t stepcounter_bit_set          : 1;
  uint8_t not_used0                    : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_src_t;

#define LSM6DSV80X_EMB_FUNC_INIT_A                0x66U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t sflp_game_init               : 1;
  uint8_t not_used2                    : 1;
  uint8_t step_det_init                : 1;
  uint8_t tilt_init                    : 1;
  uint8_t sig_mot_init                 : 1;
  uint8_t not_used1                    : 1;
  uint8_t mlc_before_fsm_init          : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc_before_fsm_init          : 1;
  uint8_t not_used1                    : 1;
  uint8_t sig_mot_init                 : 1;
  uint8_t tilt_init                    : 1;
  uint8_t step_det_init                : 1;
  uint8_t not_used2                    : 1;
  uint8_t sflp_game_init               : 1;
  uint8_t not_used0                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_init_a_t;

#define LSM6DSV80X_EMB_FUNC_INIT_B                0x67U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_init                     : 1;
  uint8_t not_used0                    : 1;
  uint8_t pt_init                      : 1;
  uint8_t fifo_compr_init              : 1;
  uint8_t mlc_init                     : 1;
  uint8_t not_used1                    : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 3;
  uint8_t mlc_init                     : 1;
  uint8_t fifo_compr_init              : 1;
  uint8_t pt_init                      : 1;
  uint8_t not_used0                    : 1;
  uint8_t fsm_init                     : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_init_b_t;

#define LSM6DSV80X_EMB_FUNC_SENSOR_CONV_EN        0x6EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl_hg_conv_en                : 1;
  uint8_t gyro_conv_en                 : 1;
  uint8_t temp_conv_en                 : 1;
  uint8_t ext_sensor_conv_en           : 1;
  uint8_t not_used0                    : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 4;
  uint8_t ext_sensor_conv_en           : 1;
  uint8_t temp_conv_en                 : 1;
  uint8_t gyro_conv_en                 : 1;
  uint8_t xl_hg_conv_en                : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_emb_func_sensor_conv_en_t;

#define LSM6DSV80X_MLC1_SRC                       0x70U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc1_src                     : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc1_src                     : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc1_src_t;

#define LSM6DSV80X_MLC2_SRC                       0x71U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc2_src                     : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc2_src                     : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc2_src_t;

#define LSM6DSV80X_MLC3_SRC                       0x72U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc3_src                     : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc3_src                     : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc3_src_t;

#define LSM6DSV80X_MLC4_SRC                       0x73U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc4_src                     : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc4_src                     : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc4_src_t;

#define LSM6DSV80X_MLC5_SRC                       0x74U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc5_src                     : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc5_src                     : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc5_src_t;

#define LSM6DSV80X_MLC6_SRC                       0x75U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc6_src                     : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc6_src                     : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc6_src_t;

#define LSM6DSV80X_MLC7_SRC                       0x76U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc7_src                     : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc7_src                     : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc7_src_t;

#define LSM6DSV80X_MLC8_SRC                       0x77U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc8_src                     : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc8_src                     : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc8_src_t;

/**
  * @}
  *
  */

/** @defgroup bitfields page pg0_emb_adv
  * @{
  *
  */
#define LSM6DSV80X_EMB_ADV_PG_0                   0x000U

#define LSM6DSV80X_FSM_EXT_SENSITIVITY_L          0xBAU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_s                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_s                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_sensitivity_l_t;

#define LSM6DSV80X_FSM_EXT_SENSITIVITY_H          0xBBU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_s                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_s                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_sensitivity_h_t;

#define LSM6DSV80X_FSM_EXT_OFFX_L                 0xC0U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_offx                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_offx                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_offx_l_t;

#define LSM6DSV80X_FSM_EXT_OFFX_H                 0xC1U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_offx                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_offx                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_offx_h_t;

#define LSM6DSV80X_FSM_EXT_OFFY_L                 0xC2U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_offy                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_offy                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_offy_l_t;

#define LSM6DSV80X_FSM_EXT_OFFY_H                 0xC3U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_offy                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_offy                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_offy_h_t;

#define LSM6DSV80X_FSM_EXT_OFFZ_L                 0xC4U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_offz                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_offz                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_offz_l_t;

#define LSM6DSV80X_FSM_EXT_OFFZ_H                 0xC5U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_offz                 : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_offz                 : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_offz_h_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_XX_L            0xC6U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_xx               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_xx               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_xx_l_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_XX_H            0xC7U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_xx               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_xx               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_xx_h_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_XY_L            0xC8U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_xy               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_xy               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_xy_l_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_XY_H            0xC9U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_xy               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_xy               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_xy_h_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_XZ_L            0xCAU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_xz               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_xz               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_xz_l_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_XZ_H            0xCBU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_xz               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_xz               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_xz_h_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_YY_L            0xCCU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_yy               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_yy               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_yy_l_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_YY_H            0xCDU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_yy               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_yy               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_yy_h_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_YZ_L            0xCEU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_yz               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_yz               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_yz_l_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_YZ_H            0xCFU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_yz               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_yz               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_yz_h_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_ZZ_L            0xD0U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_zz               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_zz               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_zz_l_t;

#define LSM6DSV80X_FSM_EXT_MATRIX_ZZ_H            0xD1U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_ext_mat_zz               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_ext_mat_zz               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_ext_matrix_zz_h_t;

#define LSM6DSV80X_EXT_CFG_A                      0xD4U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ext_z_axis                   : 3;
  uint8_t not_used0                    : 1;
  uint8_t ext_y_axis                   : 3;
  uint8_t not_used1                    : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 1;
  uint8_t ext_y_axis                   : 3;
  uint8_t not_used0                    : 1;
  uint8_t ext_z_axis                   : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ext_cfg_a_t;

#define LSM6DSV80X_EXT_CFG_B                      0xD5U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ext_x_axis                   : 3;
  uint8_t not_used0                    : 5;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 5;
  uint8_t ext_x_axis                   : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ext_cfg_b_t;

/**
  * @}
  *
  */

/** @defgroup bitfields page pg1_emb_adv
  * @{
  *
  */
#define LSM6DSV80X_EMB_ADV_PG_1                   0x100U

#define LSM6DSV80X_XL_HG_SENSITIVITY_L            0x58U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl_hg_s                      : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t xl_hg_s                      : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_xl_hg_sensitivity_l_t;

#define LSM6DSV80X_XL_HG_SENSITIVITY_H            0x59U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t xl_hg_s                      : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t xl_hg_s                      : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_xl_hg_sensitivity_h_t;

#define LSM6DSV80X_FSM_LC_TIMEOUT_L               0x7AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_lc_timeout               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_lc_timeout               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_lc_timeout_l_t;

#define LSM6DSV80X_FSM_LC_TIMEOUT_H               0x7BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_lc_timeout               : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_lc_timeout               : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_lc_timeout_h_t;

#define LSM6DSV80X_FSM_PROGRAMS                   0x7CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_n_prog                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_n_prog                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_programs_t;

#define LSM6DSV80X_FSM_START_ADD_L                0x7EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_start                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_start                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_start_add_l_t;

#define LSM6DSV80X_FSM_START_ADD_H                0x7FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t fsm_start                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t fsm_start                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_fsm_start_add_h_t;

#define LSM6DSV80X_PEDO_CMD_REG                   0x83U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 2;
  uint8_t fp_rejection_en              : 1;
  uint8_t carry_count_en               : 1;
  uint8_t not_used1                    : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 4;
  uint8_t carry_count_en               : 1;
  uint8_t fp_rejection_en              : 1;
  uint8_t not_used0                    : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_pedo_cmd_reg_t;

#define LSM6DSV80X_PEDO_DEB_STEPS_CONF            0x84U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t deb_step                     : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t deb_step                     : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_pedo_deb_steps_conf_t;

#define LSM6DSV80X_PEDO_SC_DELTAT_L               0xD0U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t pd_sc                        : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t pd_sc                        : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_pedo_sc_deltat_l_t;

#define LSM6DSV80X_PEDO_SC_DELTAT_H               0xD1U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t pd_sc                        : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t pd_sc                        : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_pedo_sc_deltat_h_t;

#define LSM6DSV80X_MLC_EXT_SENSITIVITY_L          0xE8U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc_ext_s                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc_ext_s                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc_ext_sensitivity_l_t;

#define LSM6DSV80X_MLC_EXT_SENSITIVITY_H          0xE9U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t mlc_ext_s                    : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t mlc_ext_s                    : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_mlc_ext_sensitivity_h_t;

/** @defgroup bitfields page pg2_emb_adv
  * @{
  *
  */
#define LSM6DSV80X_EMB_ADV_PG_2                   0x200U

#define LSM6DSV80X_EXT_FORMAT                     0x00
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t not_used0                    : 1;
  uint8_t ext_format_sel               : 1;
  uint8_t not_used1                    : 6;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used1                    : 6;
  uint8_t ext_format_sel               : 1;
  uint8_t not_used0                    : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ext_format_t;

#define LSM6DSV80X_EXT_3BYTE_SENSITIVITY_L        0x02U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ext_3byte_s                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ext_3byte_s                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ext_3byte_sensitivity_l_t;

#define LSM6DSV80X_EXT_3BYTE_SENSITIVITY_H        0x03U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ext_3byte_s                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ext_3byte_s                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ext_3byte_sensitivity_h_t;

#define LSM6DSV80X_EXT_3BYTE_OFFSET_XL            0x06U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ext_3byte_off                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ext_3byte_off                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ext_3byte_offset_xl_t;

#define LSM6DSV80X_EXT_3BYTE_OFFSET_L             0x07U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ext_3byte_off                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ext_3byte_off                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ext_3byte_offset_l_t;

#define LSM6DSV80X_EXT_3BYTE_OFFSET_H             0x08U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t ext_3byte_off                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t ext_3byte_off                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_ext_3byte_offset_h_t;

/**
  * @}
  *
  */

/** @defgroup bitfields page sensor_hub
  * @{
  *
  */

#define LSM6DSV80X_SENSOR_HUB_1                   0x2U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub1                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub1                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_1_t;

#define LSM6DSV80X_SENSOR_HUB_2                   0x3U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub2                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub2                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_2_t;

#define LSM6DSV80X_SENSOR_HUB_3                   0x4U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub3                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub3                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_3_t;

#define LSM6DSV80X_SENSOR_HUB_4                   0x5U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub4                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub4                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_4_t;

#define LSM6DSV80X_SENSOR_HUB_5                   0x6U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub5                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub5                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_5_t;

#define LSM6DSV80X_SENSOR_HUB_6                   0x7U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub6                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub6                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_6_t;

#define LSM6DSV80X_SENSOR_HUB_7                   0x8U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub7                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub7                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_7_t;

#define LSM6DSV80X_SENSOR_HUB_8                   0x9U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub8                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub8                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_8_t;

#define LSM6DSV80X_SENSOR_HUB_9                   0x0AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub9                   : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub9                   : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_9_t;

#define LSM6DSV80X_SENSOR_HUB_10                  0x0BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub10                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub10                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_10_t;

#define LSM6DSV80X_SENSOR_HUB_11                  0x0CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub11                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub11                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_11_t;

#define LSM6DSV80X_SENSOR_HUB_12                  0x0DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub12                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub12                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_12_t;

#define LSM6DSV80X_SENSOR_HUB_13                  0x0EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub13                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub13                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_13_t;

#define LSM6DSV80X_SENSOR_HUB_14                  0x0FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub14                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub14                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_14_t;

#define LSM6DSV80X_SENSOR_HUB_15                  0x10U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub15                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub15                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_15_t;

#define LSM6DSV80X_SENSOR_HUB_16                  0x11U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub16                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub16                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_16_t;

#define LSM6DSV80X_SENSOR_HUB_17                  0x12U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub17                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub17                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_17_t;

#define LSM6DSV80X_SENSOR_HUB_18                  0x13U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sensorhub18                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t sensorhub18                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_sensor_hub_18_t;

#define LSM6DSV80X_CONTROLLER_CONFIG              0x14U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t aux_sens_on                  : 2;
  uint8_t controller_on                : 1;
  uint8_t not_used0                    : 1;
  uint8_t pass_through_mode            : 1;
  uint8_t start_config                 : 1;
  uint8_t write_once                   : 1;
  uint8_t rst_controller_regs          : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t rst_controller_regs          : 1;
  uint8_t write_once                   : 1;
  uint8_t start_config                 : 1;
  uint8_t pass_through_mode            : 1;
  uint8_t not_used0                    : 1;
  uint8_t controller_on                : 1;
  uint8_t aux_sens_on                  : 2;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_controller_config_t;

#define LSM6DSV80X_TGT0_ADD                       0x15U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t rw_0                         : 1;
  uint8_t target0_add                  : 7;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t target0_add                  : 7;
  uint8_t rw_0                         : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt0_add_t;

#define LSM6DSV80X_TGT0_SUBADD                    0x16U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t target0_reg                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t target0_reg                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt0_subadd_t;

#define LSM6DSV80X_TGT0_CONFIG                    0x17U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t target0_numop                : 3;
  uint8_t batch_ext_sens_0_en          : 1;
  uint8_t not_used0                    : 1;
  uint8_t shub_odr                     : 3;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t shub_odr                     : 3;
  uint8_t not_used0                    : 1;
  uint8_t batch_ext_sens_0_en          : 1;
  uint8_t target0_numop                : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt0_config_t;

#define LSM6DSV80X_TGT1_ADD                       0x18U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t r_1                          : 1;
  uint8_t target1_add                  : 7;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t target1_add                  : 7;
  uint8_t r_1                          : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt1_add_t;

#define LSM6DSV80X_TGT1_SUBADD                    0x19U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t target1_reg                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t target1_reg                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt1_subadd_t;

#define LSM6DSV80X_TGT1_CONFIG                    0x1AU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t target1_numop                : 3;
  uint8_t batch_ext_sens_1_en          : 1;
  uint8_t not_used0                    : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 4;
  uint8_t batch_ext_sens_1_en          : 1;
  uint8_t target1_numop                : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt1_config_t;

#define LSM6DSV80X_TGT2_ADD                       0x1BU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t r_2                          : 1;
  uint8_t target2_add                  : 7;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t target2_add                  : 7;
  uint8_t r_2                          : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt2_add_t;

#define LSM6DSV80X_TGT2_SUBADD                    0x1CU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t target2_reg                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t target2_reg                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt2_subadd_t;

#define LSM6DSV80X_TGT2_CONFIG                    0x1DU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t target2_numop                : 3;
  uint8_t batch_ext_sens_2_en          : 1;
  uint8_t not_used0                    : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 4;
  uint8_t batch_ext_sens_2_en          : 1;
  uint8_t target2_numop                : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt2_config_t;

#define LSM6DSV80X_TGT3_ADD                       0x1EU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t r_3                          : 1;
  uint8_t target3_add                  : 7;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t target3_add                  : 7;
  uint8_t r_3                          : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt3_add_t;

#define LSM6DSV80X_TGT3_SUBADD                    0x1FU
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t target3_reg                  : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t target3_reg                  : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt3_subadd_t;

#define LSM6DSV80X_TGT3_CONFIG                    0x20U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t target3_numop                : 3;
  uint8_t batch_ext_sens_3_en          : 1;
  uint8_t not_used0                    : 4;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t not_used0                    : 4;
  uint8_t batch_ext_sens_3_en          : 1;
  uint8_t target3_numop                : 3;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_tgt3_config_t;

#define LSM6DSV80X_DATAWRITE_TGT0                 0x21U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t target0_dataw                : 8;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t target0_dataw                : 8;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_datawrite_tgt0_t;

#define LSM6DSV80X_STATUS_CONTROLLER              0x22U
typedef struct
{
#if DRV_BYTE_ORDER == DRV_LITTLE_ENDIAN
  uint8_t sens_hub_endop               : 1;
  uint8_t not_used0                    : 2;
  uint8_t target0_nack                 : 1;
  uint8_t target1_nack                 : 1;
  uint8_t target2_nack                 : 1;
  uint8_t target3_nack                 : 1;
  uint8_t wr_once_done                 : 1;
#elif DRV_BYTE_ORDER == DRV_BIG_ENDIAN
  uint8_t wr_once_done                 : 1;
  uint8_t target3_nack                 : 1;
  uint8_t target2_nack                 : 1;
  uint8_t target1_nack                 : 1;
  uint8_t target0_nack                 : 1;
  uint8_t not_used0                    : 2;
  uint8_t sens_hub_endop               : 1;
#endif /* DRV_BYTE_ORDER */
} lsm6dsv80x_status_controller_t;

/**
  * @}
  *
  */

/**
  * @defgroup LSM6DSO_Register_Union
  * @brief    This union group all the registers having a bit-field
  *           description.
  *           This union is useful but it's not needed by the driver.
  *
  *           REMOVING this union you are compliant with:
  *           MISRA-C 2012 [Rule 19.2] -> " Union are not allowed "
  *
  * @{
  *
  */
typedef union
{
  /* master page registers */
  lsm6dsv80x_func_cfg_access_t          func_cfg_access;
  lsm6dsv80x_pin_ctrl_t                 pin_ctrl;
  lsm6dsv80x_if_cfg_t                   if_cfg;
  lsm6dsv80x_odr_trig_cfg_t             odr_trig_cfg;
  lsm6dsv80x_fifo_ctrl1_t               fifo_ctrl1;
  lsm6dsv80x_fifo_ctrl2_t               fifo_ctrl2;
  lsm6dsv80x_fifo_ctrl3_t               fifo_ctrl3;
  lsm6dsv80x_fifo_ctrl4_t               fifo_ctrl4;
  lsm6dsv80x_counter_bdr_reg1_t         counter_bdr_reg1;
  lsm6dsv80x_counter_bdr_reg2_t         counter_bdr_reg2;
  lsm6dsv80x_int1_ctrl_t                int1_ctrl;
  lsm6dsv80x_int2_ctrl_t                int2_ctrl;
  lsm6dsv80x_who_am_i_t                 who_am_i;
  lsm6dsv80x_ctrl1_t                    ctrl1;
  lsm6dsv80x_ctrl2_t                    ctrl2;
  lsm6dsv80x_ctrl3_t                    ctrl3;
  lsm6dsv80x_ctrl4_t                    ctrl4;
  lsm6dsv80x_ctrl5_t                    ctrl5;
  lsm6dsv80x_ctrl6_t                    ctrl6;
  lsm6dsv80x_ctrl7_t                    ctrl7;
  lsm6dsv80x_ctrl8_t                    ctrl8;
  lsm6dsv80x_ctrl9_t                    ctrl9;
  lsm6dsv80x_ctrl10_t                   ctrl10;
  lsm6dsv80x_ctrl_status_t              ctrl_status;
  lsm6dsv80x_fifo_status1_t             fifo_status1;
  lsm6dsv80x_fifo_status2_t             fifo_status2;
  lsm6dsv80x_all_int_src_t              all_int_src;
  lsm6dsv80x_status_reg_t               status_reg;
  lsm6dsv80x_out_temp_l_t               out_temp_l;
  lsm6dsv80x_out_temp_h_t               out_temp_h;
  lsm6dsv80x_outx_l_g_t                 outx_l_g;
  lsm6dsv80x_outx_h_g_t                 outx_h_g;
  lsm6dsv80x_outy_l_g_t                 outy_l_g;
  lsm6dsv80x_outy_h_g_t                 outy_h_g;
  lsm6dsv80x_outz_l_g_t                 outz_l_g;
  lsm6dsv80x_outz_h_g_t                 outz_h_g;
  lsm6dsv80x_outx_l_a_t                 outx_l_a;
  lsm6dsv80x_outx_h_a_t                 outx_h_a;
  lsm6dsv80x_outy_l_a_t                 outy_l_a;
  lsm6dsv80x_outy_h_a_t                 outy_h_a;
  lsm6dsv80x_outz_l_a_t                 outz_l_a;
  lsm6dsv80x_outz_h_a_t                 outz_h_a;
  lsm6dsv80x_ui_outx_l_a_hg_t           ui_outx_l_a_hg;
  lsm6dsv80x_ui_outx_h_a_hg_t           ui_outx_h_a_hg;
  lsm6dsv80x_ui_outy_l_a_hg_t           ui_outy_l_a_hg;
  lsm6dsv80x_ui_outy_h_a_hg_t           ui_outy_h_a_hg;
  lsm6dsv80x_ui_outz_l_a_hg_t           ui_outz_l_a_hg;
  lsm6dsv80x_ui_outz_h_a_hg_t           ui_outz_h_a_hg;
  lsm6dsv80x_timestamp0_t               timestamp0;
  lsm6dsv80x_timestamp1_t               timestamp1;
  lsm6dsv80x_timestamp2_t               timestamp2;
  lsm6dsv80x_timestamp3_t               timestamp3;
  lsm6dsv80x_wake_up_src_t              wake_up_src;
  lsm6dsv80x_tap_src_t                  tap_src;
  lsm6dsv80x_d6d_src_t                  d6d_src;
  lsm6dsv80x_status_controller_mainpage_t   status_controller_mainpage;
  lsm6dsv80x_emb_func_status_mainpage_t emb_func_status_mainpage;
  lsm6dsv80x_fsm_status_mainpage_t      fsm_status_mainpage;
  lsm6dsv80x_mlc_status_mainpage_t      mlc_status_mainpage;
  lsm6dsv80x_hg_wake_up_src_t           hg_wake_up_src;
  lsm6dsv80x_ctrl2_xl_hg_t              ctrl2_xl_hg;
  lsm6dsv80x_ctrl1_xl_hg_t              ctrl1_xl_hg;
  lsm6dsv80x_internal_freq_t            internal_freq;
  lsm6dsv80x_functions_enable_t         functions_enable;
  lsm6dsv80x_inactivity_dur_t           inactivity_dur;
  lsm6dsv80x_inactivity_ths_t           inactivity_ths;
  lsm6dsv80x_tap_cfg0_t                 tap_cfg0;
  lsm6dsv80x_tap_cfg1_t                 tap_cfg1;
  lsm6dsv80x_tap_cfg2_t                 tap_cfg2;
  lsm6dsv80x_tap_ths_6d_t               tap_ths_6d;
  lsm6dsv80x_tap_dur_t                  tap_dur;
  lsm6dsv80x_wake_up_ths_t              wake_up_ths;
  lsm6dsv80x_wake_up_dur_t              wake_up_dur;
  lsm6dsv80x_free_fall_t                free_fall;
  lsm6dsv80x_md1_cfg_t                  md1_cfg;
  lsm6dsv80x_md2_cfg_t                  md2_cfg;
  lsm6dsv80x_emb_func_cfg_t             emb_func_cfg;
  lsm6dsv80x_hg_x_ofs_usr_t             hg_x_ofs_usr;
  lsm6dsv80x_hg_y_ofs_usr_t             hg_y_ofs_usr;
  lsm6dsv80x_hg_z_ofs_usr_t             hg_z_ofs_usr;
  lsm6dsv80x_x_ofs_usr_t                x_ofs_usr;
  lsm6dsv80x_y_ofs_usr_t                y_ofs_usr;
  lsm6dsv80x_z_ofs_usr_t                z_ofs_usr;
  lsm6dsv80x_fifo_data_out_tag_t        fifo_data_out_tag;
  lsm6dsv80x_fifo_data_out_x_l_t        fifo_data_out_x_l;
  lsm6dsv80x_fifo_data_out_x_h_t        fifo_data_out_x_h;
  lsm6dsv80x_fifo_data_out_y_l_t        fifo_data_out_y_l;
  lsm6dsv80x_fifo_data_out_y_h_t        fifo_data_out_y_h;
  lsm6dsv80x_fifo_data_out_z_l_t        fifo_data_out_z_l;
  lsm6dsv80x_fifo_data_out_z_h_t        fifo_data_out_z_h;
  /* Embedded functions registers */
  lsm6dsv80x_page_sel_t                 page_sel;
  lsm6dsv80x_emb_func_en_a_t            emb_func_en_a;
  lsm6dsv80x_emb_func_en_b_t            emb_func_en_b;
  lsm6dsv80x_emb_func_exec_status_t     emb_func_exec_status;
  lsm6dsv80x_page_address_t             page_address;
  lsm6dsv80x_page_value_t               page_value;
  lsm6dsv80x_emb_func_int1_t            emb_func_int1;
  lsm6dsv80x_fsm_int1_t                 fsm_int1;
  lsm6dsv80x_mlc_int1_t                 mlc_int1;
  lsm6dsv80x_emb_func_int2_t            emb_func_int2;
  lsm6dsv80x_fsm_int2_t                 fsm_int2;
  lsm6dsv80x_mlc_int2_t                 mlc_int2;
  lsm6dsv80x_emb_func_status_t          emb_func_status;
  lsm6dsv80x_fsm_status_t               fsm_status;
  lsm6dsv80x_mlc_status_t               mlc_status;
  lsm6dsv80x_page_rw_t                  page_rw;
  lsm6dsv80x_sflp_gbiasx_l_t            sflp_gbiasx_l;
  lsm6dsv80x_sflp_gbiasx_h_t            sflp_gbiasx_h;
  lsm6dsv80x_sflp_gbiasy_l_t            sflp_gbiasy_l;
  lsm6dsv80x_sflp_gbiasy_h_t            sflp_gbiasy_h;
  lsm6dsv80x_sflp_gbiasz_l_t            sflp_gbiasz_l;
  lsm6dsv80x_sflp_gbiasz_h_t            sflp_gbiasz_h;
  lsm6dsv80x_sflp_gravx_l_t             sflp_gravx_l;
  lsm6dsv80x_sflp_gravx_h_t             sflp_gravx_h;
  lsm6dsv80x_sflp_gravy_l_t             sflp_gravy_l;
  lsm6dsv80x_sflp_gravy_h_t             sflp_gravy_h;
  lsm6dsv80x_sflp_gravz_l_t             sflp_gravz_l;
  lsm6dsv80x_sflp_gravz_h_t             sflp_gravz_h;
  lsm6dsv80x_sflp_quatw_l_t             sflp_quatw_l;
  lsm6dsv80x_sflp_quatw_h_t             sflp_quatw_h;
  lsm6dsv80x_sflp_quatx_l_t             sflp_quatx_l;
  lsm6dsv80x_sflp_quatx_h_t             sflp_quatx_h;
  lsm6dsv80x_sflp_quaty_l_t             sflp_quaty_l;
  lsm6dsv80x_sflp_quaty_h_t             sflp_quaty_h;
  lsm6dsv80x_sflp_quatz_l_t             sflp_quatz_l;
  lsm6dsv80x_sflp_quatz_h_t             sflp_quatz_h;
  lsm6dsv80x_sflp_gbiasx_init_l_t       sflp_gbiasx_init_l;
  lsm6dsv80x_sflp_gbiasx_init_h_t       sflp_gbiasx_init_h;
  lsm6dsv80x_sflp_gbiasy_init_l_t       sflp_gbiasy_init_l;
  lsm6dsv80x_sflp_gbiasy_init_h_t       sflp_gbiasy_init_h;
  lsm6dsv80x_sflp_gbiasz_init_l_t       sflp_gbiasz_init_l;
  lsm6dsv80x_sflp_gbiasz_init_h_t       sflp_gbiasz_init_h;
  lsm6dsv80x_emb_func_fifo_en_a_t       emb_func_fifo_en_a;
  lsm6dsv80x_emb_func_fifo_en_b_t       emb_func_fifo_en_b;
  lsm6dsv80x_fsm_enable_t               fsm_enable;
  lsm6dsv80x_fsm_long_counter_l_t       fsm_long_counter_l;
  lsm6dsv80x_fsm_long_counter_h_t       fsm_long_counter_h;
  lsm6dsv80x_int_ack_mask_t             int_ack_mask;
  lsm6dsv80x_fsm_outs1_t                fsm_outs1;
  lsm6dsv80x_fsm_outs2_t                fsm_outs2;
  lsm6dsv80x_fsm_outs3_t                fsm_outs3;
  lsm6dsv80x_fsm_outs4_t                fsm_outs4;
  lsm6dsv80x_fsm_outs5_t                fsm_outs5;
  lsm6dsv80x_fsm_outs6_t                fsm_outs6;
  lsm6dsv80x_fsm_outs7_t                fsm_outs7;
  lsm6dsv80x_fsm_outs8_t                fsm_outs8;
  lsm6dsv80x_sflp_odr_t                 sflp_odr;
  lsm6dsv80x_fsm_odr_t                  fsm_odr;
  lsm6dsv80x_mlc_odr_t                  mlc_odr;
  lsm6dsv80x_step_counter_l_t           step_counter_l;
  lsm6dsv80x_step_counter_h_t           step_counter_h;
  lsm6dsv80x_emb_func_src_t             emb_func_src;
  lsm6dsv80x_emb_func_init_a_t          emb_func_init_a;
  lsm6dsv80x_emb_func_init_b_t          emb_func_init_b;
  lsm6dsv80x_emb_func_sensor_conv_en_t  emb_func_sensor_conv_en;
  lsm6dsv80x_mlc1_src_t                 mlc1_src;
  lsm6dsv80x_mlc2_src_t                 mlc2_src;
  lsm6dsv80x_mlc3_src_t                 mlc3_src;
  lsm6dsv80x_mlc4_src_t                 mlc4_src;
  lsm6dsv80x_mlc5_src_t                 mlc5_src;
  lsm6dsv80x_mlc6_src_t                 mlc6_src;
  lsm6dsv80x_mlc7_src_t                 mlc7_src;
  /* Embedded functions extended page 0 registers */
  lsm6dsv80x_fsm_ext_sensitivity_l_t    fsm_ext_sensitivity_l;
  lsm6dsv80x_fsm_ext_sensitivity_h_t    fsm_ext_sensitivity_h;
  lsm6dsv80x_fsm_ext_offx_l_t           fsm_ext_offx_l;
  lsm6dsv80x_fsm_ext_offx_h_t           fsm_ext_offx_h;
  lsm6dsv80x_fsm_ext_offy_l_t           fsm_ext_offy_l;
  lsm6dsv80x_fsm_ext_offy_h_t           fsm_ext_offy_h;
  lsm6dsv80x_fsm_ext_offz_l_t           fsm_ext_offz_l;
  lsm6dsv80x_fsm_ext_offz_h_t           fsm_ext_offz_h;
  lsm6dsv80x_fsm_ext_matrix_xx_l_t      fsm_ext_matrix_xx_l;
  lsm6dsv80x_fsm_ext_matrix_xx_h_t      fsm_ext_matrix_xx_h;
  lsm6dsv80x_fsm_ext_matrix_xy_l_t      fsm_ext_matrix_xy_l;
  lsm6dsv80x_fsm_ext_matrix_xy_h_t      fsm_ext_matrix_xy_h;
  lsm6dsv80x_fsm_ext_matrix_xz_l_t      fsm_ext_matrix_xz_l;
  lsm6dsv80x_fsm_ext_matrix_xz_h_t      fsm_ext_matrix_xz_h;
  lsm6dsv80x_fsm_ext_matrix_yy_l_t      fsm_ext_matrix_yy_l;
  lsm6dsv80x_fsm_ext_matrix_yy_h_t      fsm_ext_matrix_yy_h;
  lsm6dsv80x_fsm_ext_matrix_yz_l_t      fsm_ext_matrix_yz_l;
  lsm6dsv80x_fsm_ext_matrix_yz_h_t      fsm_ext_matrix_yz_h;
  lsm6dsv80x_fsm_ext_matrix_zz_l_t      fsm_ext_matrix_zz_l;
  lsm6dsv80x_fsm_ext_matrix_zz_h_t      fsm_ext_matrix_zz_h;
  lsm6dsv80x_ext_cfg_a_t                ext_cfg_a;
  lsm6dsv80x_ext_cfg_b_t                ext_cfg_b;
  /* Embedded functions extended page 1 registers */
  lsm6dsv80x_xl_hg_sensitivity_l_t      xl_hg_sensitivity_l;
  lsm6dsv80x_xl_hg_sensitivity_h_t      xl_hg_sensitivity_h;
  lsm6dsv80x_fsm_lc_timeout_l_t         fsm_lc_timeout_l;
  lsm6dsv80x_fsm_lc_timeout_h_t         fsm_lc_timeout_h;
  lsm6dsv80x_fsm_programs_t             fsm_programs;
  lsm6dsv80x_fsm_start_add_l_t          fsm_start_add_l;
  lsm6dsv80x_fsm_start_add_h_t          fsm_start_add_h;
  lsm6dsv80x_pedo_cmd_reg_t             pedo_cmd_reg;
  lsm6dsv80x_pedo_deb_steps_conf_t      pedo_deb_steps_conf;
  lsm6dsv80x_pedo_sc_deltat_l_t         pedo_sc_deltat_l;
  lsm6dsv80x_pedo_sc_deltat_h_t         pedo_sc_deltat_h;
  lsm6dsv80x_mlc_ext_sensitivity_l_t    mlc_ext_sensitivity_l;
  lsm6dsv80x_mlc_ext_sensitivity_h_t    mlc_ext_sensitivity_h;
  /* Embedded functions extended page 2 registers */
  lsm6dsv80x_ext_format_t               ext_format;
  lsm6dsv80x_ext_3byte_sensitivity_l_t  ext_3byte_sensitivity_l;
  lsm6dsv80x_ext_3byte_sensitivity_h_t  ext_3byte_sensitivity_h;
  lsm6dsv80x_ext_3byte_offset_xl_t      ext_3byte_offset_xl;
  lsm6dsv80x_ext_3byte_offset_l_t       ext_3byte_offset_l;
  lsm6dsv80x_ext_3byte_offset_h_t       ext_3byte_offset_h;
  /* Sensor HUB registers */
  lsm6dsv80x_sensor_hub_1_t             sensor_hub_1;
  lsm6dsv80x_sensor_hub_2_t             sensor_hub_2;
  lsm6dsv80x_sensor_hub_3_t             sensor_hub_3;
  lsm6dsv80x_sensor_hub_4_t             sensor_hub_4;
  lsm6dsv80x_sensor_hub_5_t             sensor_hub_5;
  lsm6dsv80x_sensor_hub_6_t             sensor_hub_6;
  lsm6dsv80x_sensor_hub_7_t             sensor_hub_7;
  lsm6dsv80x_sensor_hub_8_t             sensor_hub_8;
  lsm6dsv80x_sensor_hub_9_t             sensor_hub_9;
  lsm6dsv80x_sensor_hub_10_t            sensor_hub_10;
  lsm6dsv80x_sensor_hub_11_t            sensor_hub_11;
  lsm6dsv80x_sensor_hub_12_t            sensor_hub_12;
  lsm6dsv80x_sensor_hub_13_t            sensor_hub_13;
  lsm6dsv80x_sensor_hub_14_t            sensor_hub_14;
  lsm6dsv80x_sensor_hub_15_t            sensor_hub_15;
  lsm6dsv80x_sensor_hub_16_t            sensor_hub_16;
  lsm6dsv80x_sensor_hub_17_t            sensor_hub_17;
  lsm6dsv80x_sensor_hub_18_t            sensor_hub_18;
  lsm6dsv80x_controller_config_t        controller_config;
  lsm6dsv80x_tgt0_add_t                 tgt0_add;
  lsm6dsv80x_tgt0_subadd_t              tgt0_subadd;
  lsm6dsv80x_tgt0_config_t              tgt0_config;
  lsm6dsv80x_tgt1_add_t                 tgt1_add;
  lsm6dsv80x_tgt1_subadd_t              tgt1_subadd;
  lsm6dsv80x_tgt1_config_t              tgt1_config;
  lsm6dsv80x_tgt2_add_t                 tgt2_add;
  lsm6dsv80x_tgt2_subadd_t              tgt2_subadd;
  lsm6dsv80x_tgt2_config_t              tgt2_config;
  lsm6dsv80x_tgt3_add_t                 tgt3_add;
  lsm6dsv80x_tgt3_subadd_t              tgt3_subadd;
  lsm6dsv80x_tgt3_config_t              tgt3_config;
  lsm6dsv80x_datawrite_tgt0_t           datawrite_tgt0;
  lsm6dsv80x_status_controller_t        status_controller;
  bitwise_t                             bitwise;
  uint8_t                               byte;
} lsm6dsv80x_reg_t;

/**
  * @}
  *
  */

#ifndef __weak
#define __weak __attribute__((weak))
#endif /* __weak */

/*
 * These are the basic platform dependent I/O routines to read
 * and write device registers connected on a standard bus.
 * The driver keeps offering a default implementation based on function
 * pointers to read/write routines for backward compatibility.
 * The __weak directive allows the final application to overwrite
 * them with a custom implementation.
 */

int32_t lsm6dsv80x_read_reg(const stmdev_ctx_t *ctx, uint8_t reg,
                            uint8_t *data,
                            uint16_t len);
int32_t lsm6dsv80x_write_reg(const stmdev_ctx_t *ctx, uint8_t reg,
                             uint8_t *data,
                             uint16_t len);

float_t lsm6dsv80x_from_sflp_to_mg(int16_t lsb);
float_t lsm6dsv80x_from_fs2_to_mg(int16_t lsb);
float_t lsm6dsv80x_from_fs4_to_mg(int16_t lsb);
float_t lsm6dsv80x_from_fs8_to_mg(int16_t lsb);
float_t lsm6dsv80x_from_fs16_to_mg(int16_t lsb);

float_t lsm6dsv80x_from_fs32_to_mg(int16_t lsb);
float_t lsm6dsv80x_from_fs64_to_mg(int16_t lsb);
float_t lsm6dsv80x_from_fs80_to_mg(int16_t lsb);

float_t lsm6dsv80x_from_fs500_to_mdps(int16_t lsb);
float_t lsm6dsv80x_from_fs250_to_mdps(int16_t lsb);
float_t lsm6dsv80x_from_fs1000_to_mdps(int16_t lsb);
float_t lsm6dsv80x_from_fs2000_to_mdps(int16_t lsb);
float_t lsm6dsv80x_from_fs4000_to_mdps(int16_t lsb);

float_t lsm6dsv80x_from_lsb_to_celsius(int16_t lsb);

uint64_t lsm6dsv80x_from_lsb_to_nsec(uint32_t lsb);

float_t lsm6dsv80x_from_lsb_to_mv(int16_t lsb);

float_t lsm6dsv80x_from_gbias_lsb_to_mdps(int16_t lsb);
float_t lsm6dsv80x_from_gravity_lsb_to_mg(int16_t lsb);
float_t lsm6dsv80x_from_quaternion_lsb_to_float(uint16_t lsb);

uint32_t lsm6dsv80x_from_f16_to_f32(uint16_t val);

int32_t lsm6dsv80x_xl_offset_on_out_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_xl_offset_on_out_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  float_t z_mg;
  float_t y_mg;
  float_t x_mg;
} lsm6dsv80x_xl_offset_mg_t;
int32_t lsm6dsv80x_xl_offset_mg_set(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_xl_offset_mg_t val);
int32_t lsm6dsv80x_xl_offset_mg_get(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_xl_offset_mg_t *val);

int32_t lsm6dsv80x_hg_xl_offset_mg_set(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_xl_offset_mg_t val);
int32_t lsm6dsv80x_hg_xl_offset_mg_get(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_xl_offset_mg_t *val);

typedef enum
{
  LSM6DSV80X_READY             = 0x0,
  LSM6DSV80X_GLOBAL_RST        = 0x1,
  LSM6DSV80X_RESTORE_CAL_PARAM = 0x2,
  LSM6DSV80X_RESTORE_CTRL_REGS = 0x4,
} lsm6dsv80x_reset_t;
int32_t lsm6dsv80x_reset_set(const stmdev_ctx_t *ctx, lsm6dsv80x_reset_t val);
int32_t lsm6dsv80x_reset_get(const stmdev_ctx_t *ctx, lsm6dsv80x_reset_t *val);

typedef enum
{
  LSM6DSV80X_MAIN_MEM_BANK       = 0x0,
  LSM6DSV80X_EMBED_FUNC_MEM_BANK = 0x1,
  LSM6DSV80X_SENSOR_HUB_MEM_BANK = 0x2,
} lsm6dsv80x_mem_bank_t;
int32_t lsm6dsv80x_mem_bank_set(const stmdev_ctx_t *ctx, lsm6dsv80x_mem_bank_t val);
int32_t lsm6dsv80x_mem_bank_get(const stmdev_ctx_t *ctx, lsm6dsv80x_mem_bank_t *val);

int32_t lsm6dsv80x_device_id_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_ODR_OFF              = 0x0,
  LSM6DSV80X_ODR_AT_1Hz875        = 0x1,
  LSM6DSV80X_ODR_AT_7Hz5          = 0x2,
  LSM6DSV80X_ODR_AT_15Hz          = 0x3,
  LSM6DSV80X_ODR_AT_30Hz          = 0x4,
  LSM6DSV80X_ODR_AT_60Hz          = 0x5,
  LSM6DSV80X_ODR_AT_120Hz         = 0x6,
  LSM6DSV80X_ODR_AT_240Hz         = 0x7,
  LSM6DSV80X_ODR_AT_480Hz         = 0x8,
  LSM6DSV80X_ODR_AT_960Hz         = 0x9,
  LSM6DSV80X_ODR_AT_1920Hz        = 0xA,
  LSM6DSV80X_ODR_AT_3840Hz        = 0xB,
  LSM6DSV80X_ODR_AT_7680Hz        = 0xC,
  LSM6DSV80X_ODR_HA01_AT_15Hz625  = 0x13,
  LSM6DSV80X_ODR_HA01_AT_31Hz25   = 0x14,
  LSM6DSV80X_ODR_HA01_AT_62Hz5    = 0x15,
  LSM6DSV80X_ODR_HA01_AT_125Hz    = 0x16,
  LSM6DSV80X_ODR_HA01_AT_250Hz    = 0x17,
  LSM6DSV80X_ODR_HA01_AT_500Hz    = 0x18,
  LSM6DSV80X_ODR_HA01_AT_1000Hz   = 0x19,
  LSM6DSV80X_ODR_HA01_AT_2000Hz   = 0x1A,
  LSM6DSV80X_ODR_HA01_AT_4000Hz   = 0x1B,
  LSM6DSV80X_ODR_HA01_AT_8000Hz   = 0x1C,
  LSM6DSV80X_ODR_HA02_AT_12Hz5    = 0x23,
  LSM6DSV80X_ODR_HA02_AT_25Hz     = 0x24,
  LSM6DSV80X_ODR_HA02_AT_50Hz     = 0x25,
  LSM6DSV80X_ODR_HA02_AT_100Hz    = 0x26,
  LSM6DSV80X_ODR_HA02_AT_200Hz    = 0x27,
  LSM6DSV80X_ODR_HA02_AT_400Hz    = 0x28,
  LSM6DSV80X_ODR_HA02_AT_800Hz    = 0x29,
  LSM6DSV80X_ODR_HA02_AT_1600Hz   = 0x2A,
  LSM6DSV80X_ODR_HA02_AT_3200Hz   = 0x2B,
  LSM6DSV80X_ODR_HA02_AT_6400Hz   = 0x2C,
  LSM6DSV80X_ODR_HA03_AT_13Hz     = 0x33,
  LSM6DSV80X_ODR_HA03_AT_26Hz     = 0x34,
  LSM6DSV80X_ODR_HA03_AT_52Hz     = 0x35,
  LSM6DSV80X_ODR_HA03_AT_104Hz    = 0x36,
  LSM6DSV80X_ODR_HA03_AT_208Hz    = 0x37,
  LSM6DSV80X_ODR_HA03_AT_417Hz    = 0x38,
  LSM6DSV80X_ODR_HA03_AT_833Hz    = 0x39,
  LSM6DSV80X_ODR_HA03_AT_1667Hz   = 0x3A,
  LSM6DSV80X_ODR_HA03_AT_3333Hz   = 0x3B,
  LSM6DSV80X_ODR_HA03_AT_6667Hz   = 0x3C,
} lsm6dsv80x_data_rate_t;
int32_t lsm6dsv80x_xl_data_rate_set(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_data_rate_t val);
int32_t lsm6dsv80x_xl_data_rate_get(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_data_rate_t *val);
int32_t lsm6dsv80x_gy_data_rate_set(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_data_rate_t val);
int32_t lsm6dsv80x_gy_data_rate_get(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_data_rate_t *val);

typedef enum
{
  LSM6DSV80X_HG_XL_ODR_OFF         = 0x0,
  LSM6DSV80X_HG_XL_ODR_AT_480Hz    = 0x3,
  LSM6DSV80X_HG_XL_ODR_AT_960Hz    = 0x4,
  LSM6DSV80X_HG_XL_ODR_AT_1920Hz   = 0x5,
  LSM6DSV80X_HG_XL_ODR_AT_3840Hz   = 0x6,
  LSM6DSV80X_HG_XL_ODR_AT_7680Hz   = 0x7,
} lsm6dsv80x_hg_xl_data_rate_t;
int32_t lsm6dsv80x_hg_xl_data_rate_set(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_hg_xl_data_rate_t val,
                                       uint8_t reg_out_en);
int32_t lsm6dsv80x_hg_xl_data_rate_get(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_hg_xl_data_rate_t *val,
                                       uint8_t *reg_out_en);

typedef enum
{
  LSM6DSV80X_XL_HIGH_PERFORMANCE_MD   = 0x0,
  LSM6DSV80X_XL_HIGH_ACCURACY_ODR_MD  = 0x1,
  LSM6DSV80X_XL_ODR_TRIGGERED_MD      = 0x3,
  LSM6DSV80X_XL_LOW_POWER_2_AVG_MD    = 0x4,
  LSM6DSV80X_XL_LOW_POWER_4_AVG_MD    = 0x5,
  LSM6DSV80X_XL_LOW_POWER_8_AVG_MD    = 0x6,
  LSM6DSV80X_XL_NORMAL_MD             = 0x7,
} lsm6dsv80x_xl_mode_t;
int32_t lsm6dsv80x_xl_mode_set(const stmdev_ctx_t *ctx, lsm6dsv80x_xl_mode_t val);
int32_t lsm6dsv80x_xl_mode_get(const stmdev_ctx_t *ctx, lsm6dsv80x_xl_mode_t *val);

typedef enum
{
  LSM6DSV80X_GY_HIGH_PERFORMANCE_MD   = 0x0,
  LSM6DSV80X_GY_HIGH_ACCURACY_ODR_MD  = 0x1,
  LSM6DSV80X_GY_ODR_TRIGGERED_MD      = 0x3,
  LSM6DSV80X_GY_SLEEP_MD              = 0x4,
  LSM6DSV80X_GY_LOW_POWER_MD          = 0x5,
} lsm6dsv80x_gy_mode_t;
int32_t lsm6dsv80x_gy_mode_set(const stmdev_ctx_t *ctx, lsm6dsv80x_gy_mode_t val);
int32_t lsm6dsv80x_gy_mode_get(const stmdev_ctx_t *ctx, lsm6dsv80x_gy_mode_t *val);

int32_t lsm6dsv80x_auto_increment_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_auto_increment_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_block_data_update_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_block_data_update_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_odr_trig_cfg_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_odr_trig_cfg_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_DRDY_LATCHED = 0x0,
  LSM6DSV80X_DRDY_PULSED  = 0x1,
} lsm6dsv80x_data_ready_mode_t;
int32_t lsm6dsv80x_data_ready_mode_set(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_data_ready_mode_t val);
int32_t lsm6dsv80x_data_ready_mode_get(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_data_ready_mode_t *val);

typedef struct
{
  uint8_t hg_event                     : 1;
  uint8_t hg_wakeup_z                  : 1;
  uint8_t hg_wakeup_y                  : 1;
  uint8_t hg_wakeup_x                  : 1;
  uint8_t hg_wakeup                    : 1;
  uint8_t hg_wakeup_chg                : 1;
  uint8_t hg_shock                     : 1;
  uint8_t hg_shock_change              : 1;
} lsm6dsv80x_hg_event_t;
int32_t lsm6dsv80x_hg_event_get(const stmdev_ctx_t *ctx, lsm6dsv80x_hg_event_t *val);

typedef struct
{
  uint8_t hg_wakeup_ths                  : 8;
  uint8_t hg_shock_dur                   : 4;
} lsm6dsv80x_hg_wake_up_cfg_t;
int32_t lsm6dsv80x_hg_wake_up_cfg_set(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_hg_wake_up_cfg_t val);
int32_t lsm6dsv80x_hg_wake_up_cfg_get(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_hg_wake_up_cfg_t *val);

typedef struct
{
  uint8_t hg_interrupts_enable         : 1;
  uint8_t hg_wakeup_int_sel            : 1;
} lsm6dsv80x_hg_wu_interrupt_cfg_t;
int32_t lsm6dsv80x_hg_wu_interrupt_cfg_set(const stmdev_ctx_t *ctx,
                                           lsm6dsv80x_hg_wu_interrupt_cfg_t val);
int32_t lsm6dsv80x_hg_wu_interrupt_cfg_get(const stmdev_ctx_t *ctx,
                                           lsm6dsv80x_hg_wu_interrupt_cfg_t *val);

int32_t lsm6dsv80x_hg_emb_usr_off_correction_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_hg_emb_usr_off_correction_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_hg_wu_usr_off_correction_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_hg_wu_usr_off_correction_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  uint8_t enable                       : 1; /* interrupt enable */
  uint8_t lir                          : 1; /* interrupt pulsed or latched */
} lsm6dsv80x_interrupt_mode_t;
int32_t lsm6dsv80x_interrupt_enable_set(const stmdev_ctx_t *ctx,
                                        lsm6dsv80x_interrupt_mode_t val);
int32_t lsm6dsv80x_interrupt_enable_get(const stmdev_ctx_t *ctx,
                                        lsm6dsv80x_interrupt_mode_t *val);

typedef enum
{
  LSM6DSV80X_250dps  = 0x1,
  LSM6DSV80X_500dps  = 0x2,
  LSM6DSV80X_1000dps = 0x3,
  LSM6DSV80X_2000dps = 0x4,
  LSM6DSV80X_4000dps = 0x5,
} lsm6dsv80x_gy_full_scale_t;
int32_t lsm6dsv80x_gy_full_scale_set(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_gy_full_scale_t val);
int32_t lsm6dsv80x_gy_full_scale_get(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_gy_full_scale_t *val);

typedef enum
{
  LSM6DSV80X_2g  = 0x0,
  LSM6DSV80X_4g  = 0x1,
  LSM6DSV80X_8g  = 0x2,
  LSM6DSV80X_16g = 0x3,
} lsm6dsv80x_xl_full_scale_t;
int32_t lsm6dsv80x_xl_full_scale_set(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_xl_full_scale_t val);
int32_t lsm6dsv80x_xl_full_scale_get(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_xl_full_scale_t *val);

typedef enum
{
  LSM6DSV80X_32g  = 0x0,
  LSM6DSV80X_64g  = 0x1,
  LSM6DSV80X_80g = 0x2,
} lsm6dsv80x_hg_xl_full_scale_t;
int32_t lsm6dsv80x_hg_xl_full_scale_set(const stmdev_ctx_t *ctx,
                                        lsm6dsv80x_hg_xl_full_scale_t val);
int32_t lsm6dsv80x_hg_xl_full_scale_get(const stmdev_ctx_t *ctx,
                                        lsm6dsv80x_hg_xl_full_scale_t *val);

typedef enum
{
  LSM6DSV80X_ST_DISABLE  = 0x0,
  LSM6DSV80X_ST_POSITIVE = 0x1,
  LSM6DSV80X_ST_NEGATIVE = 0x2,
} lsm6dsv80x_self_test_t;
int32_t lsm6dsv80x_xl_self_test_set(const stmdev_ctx_t *ctx, lsm6dsv80x_self_test_t val);
int32_t lsm6dsv80x_xl_self_test_get(const stmdev_ctx_t *ctx, lsm6dsv80x_self_test_t *val);

int32_t lsm6dsv80x_gy_self_test_set(const stmdev_ctx_t *ctx, lsm6dsv80x_self_test_t val);
int32_t lsm6dsv80x_gy_self_test_get(const stmdev_ctx_t *ctx, lsm6dsv80x_self_test_t *val);

int32_t lsm6dsv80x_hg_xl_self_test_set(const stmdev_ctx_t *ctx, lsm6dsv80x_self_test_t val);
int32_t lsm6dsv80x_hg_xl_self_test_get(const stmdev_ctx_t *ctx, lsm6dsv80x_self_test_t *val);

typedef struct
{
  uint8_t drdy_xl                      : 1;
  uint8_t drdy_gy                      : 1;
  uint8_t drdy_temp                    : 1;
  uint8_t drdy_xlhgda                  : 1;
  uint8_t gy_settling                  : 1;
  uint8_t timestamp                    : 1;
  uint8_t hg                           : 1;
  uint8_t free_fall                    : 1;
  uint8_t wake_up                      : 1;
  uint8_t wake_up_z                    : 1;
  uint8_t wake_up_y                    : 1;
  uint8_t wake_up_x                    : 1;
  uint8_t single_tap                   : 1;
  uint8_t double_tap                   : 1;
  uint8_t tap_z                        : 1;
  uint8_t tap_y                        : 1;
  uint8_t tap_x                        : 1;
  uint8_t tap_sign                     : 1;
  uint8_t six_d                        : 1;
  uint8_t six_d_xl                     : 1;
  uint8_t six_d_xh                     : 1;
  uint8_t six_d_yl                     : 1;
  uint8_t six_d_yh                     : 1;
  uint8_t six_d_zl                     : 1;
  uint8_t six_d_zh                     : 1;
  uint8_t sleep_change                 : 1;
  uint8_t sleep_state                  : 1;
  uint8_t step_detector                : 1;
  uint8_t step_count_inc               : 1;
  uint8_t step_count_overflow          : 1;
  uint8_t step_on_delta_time           : 1;
  uint8_t emb_func_stand_by            : 1;
  uint8_t emb_func_time_exceed         : 1;
  uint8_t tilt                         : 1;
  uint8_t sig_mot                      : 1;
  uint8_t fsm_lc                       : 1;
  uint8_t fsm1                         : 1;
  uint8_t fsm2                         : 1;
  uint8_t fsm3                         : 1;
  uint8_t fsm4                         : 1;
  uint8_t fsm5                         : 1;
  uint8_t fsm6                         : 1;
  uint8_t fsm7                         : 1;
  uint8_t fsm8                         : 1;
  uint8_t mlc1                         : 1;
  uint8_t mlc2                         : 1;
  uint8_t mlc3                         : 1;
  uint8_t mlc4                         : 1;
  uint8_t mlc5                         : 1;
  uint8_t mlc6                         : 1;
  uint8_t mlc7                         : 1;
  uint8_t mlc8                         : 1;
  uint8_t sh_endop                     : 1;
  uint8_t sh_target0_nack              : 1;
  uint8_t sh_target1_nack              : 1;
  uint8_t sh_target2_nack              : 1;
  uint8_t sh_target3_nack              : 1;
  uint8_t sh_wr_once                   : 1;
  uint8_t fifo_bdr                     : 1;
  uint8_t fifo_full                    : 1;
  uint8_t fifo_ovr                     : 1;
  uint8_t fifo_th                      : 1;
} lsm6dsv80x_all_sources_t;
int32_t lsm6dsv80x_all_sources_get(const stmdev_ctx_t *ctx,
                                   lsm6dsv80x_all_sources_t *val);

typedef struct
{
  uint8_t drdy_xl                      : 1;
  uint8_t drdy_g                       : 1;
  uint8_t drdy_temp                    : 1;
  uint8_t fifo_th                      : 1;
  uint8_t fifo_ovr                     : 1;
  uint8_t fifo_full                    : 1;
  uint8_t cnt_bdr                      : 1;
  uint8_t timestamp                    : 1;
  uint8_t shub                         : 1;
  uint8_t sixd                         : 1;
  uint8_t single_tap                   : 1;
  uint8_t double_tap                   : 1;
  uint8_t wakeup                       : 1;
  uint8_t freefall                     : 1;
  uint8_t sleep_change                 : 1;
  uint8_t drdy_hg_xl                   : 1; /* High-g */
  uint8_t hg_wakeup                    : 1;
  uint8_t hg_shock_change              : 1;
  uint8_t step_detector                : 1; /* Embedded Functions */
  uint8_t tilt                         : 1;
  uint8_t sig_mot                      : 1;
  uint8_t emb_func_endop               : 1;
  uint8_t fsm1                         : 1; /* FSM */
  uint8_t fsm2                         : 1;
  uint8_t fsm3                         : 1;
  uint8_t fsm4                         : 1;
  uint8_t fsm5                         : 1;
  uint8_t fsm6                         : 1;
  uint8_t fsm7                         : 1;
  uint8_t fsm8                         : 1;
  uint8_t mlc1                         : 1; /* MLC */
  uint8_t mlc2                         : 1;
  uint8_t mlc3                         : 1;
  uint8_t mlc4                         : 1;
  uint8_t mlc5                         : 1;
  uint8_t mlc6                         : 1;
  uint8_t mlc7                         : 1;
  uint8_t mlc8                         : 1;
} lsm6dsv80x_pin_int_route_t;

int32_t lsm6dsv80x_pin_int1_route_set(const stmdev_ctx_t *ctx, lsm6dsv80x_pin_int_route_t *val);
int32_t lsm6dsv80x_pin_int1_route_get(const stmdev_ctx_t *ctx, lsm6dsv80x_pin_int_route_t *val);
int32_t lsm6dsv80x_pin_int2_route_set(const stmdev_ctx_t *ctx, lsm6dsv80x_pin_int_route_t *val);
int32_t lsm6dsv80x_pin_int2_route_get(const stmdev_ctx_t *ctx, lsm6dsv80x_pin_int_route_t *val);

int32_t lsm6dsv80x_pin_int1_route_hg_set(const stmdev_ctx_t *ctx, lsm6dsv80x_pin_int_route_t *val);
int32_t lsm6dsv80x_pin_int1_route_hg_get(const stmdev_ctx_t *ctx, lsm6dsv80x_pin_int_route_t *val);
int32_t lsm6dsv80x_pin_int2_route_hg_set(const stmdev_ctx_t *ctx, lsm6dsv80x_pin_int_route_t *val);
int32_t lsm6dsv80x_pin_int2_route_hg_get(const stmdev_ctx_t *ctx, lsm6dsv80x_pin_int_route_t *val);

int32_t lsm6dsv80x_pin_int1_route_embedded_set(const stmdev_ctx_t *ctx,
                                               lsm6dsv80x_pin_int_route_t *val);
int32_t lsm6dsv80x_pin_int1_route_embedded_get(const stmdev_ctx_t *ctx,
                                               lsm6dsv80x_pin_int_route_t *val);
int32_t lsm6dsv80x_pin_int2_route_embedded_set(const stmdev_ctx_t *ctx,
                                               lsm6dsv80x_pin_int_route_t *val);
int32_t lsm6dsv80x_pin_int2_route_embedded_get(const stmdev_ctx_t *ctx,
                                               lsm6dsv80x_pin_int_route_t *val);

typedef struct
{
  uint8_t drdy_hgxl                    : 1;
  uint8_t drdy_xl                      : 1;
  uint8_t drdy_gy                      : 1;
  uint8_t drdy_temp                    : 1;
} lsm6dsv80x_data_ready_t;
int32_t lsm6dsv80x_flag_data_ready_get(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_data_ready_t *val);

int32_t lsm6dsv80x_int_ack_mask_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_int_ack_mask_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_temperature_raw_get(const stmdev_ctx_t *ctx, int16_t *val);

int32_t lsm6dsv80x_angular_rate_raw_get(const stmdev_ctx_t *ctx, int16_t *val);

int32_t lsm6dsv80x_acceleration_raw_get(const stmdev_ctx_t *ctx, int16_t *val);

int32_t lsm6dsv80x_hg_acceleration_raw_get(const stmdev_ctx_t *ctx, int16_t *val);

int32_t lsm6dsv80x_sflp_gbias_raw_get(const stmdev_ctx_t *ctx, int16_t *val);
int32_t lsm6dsv80x_sflp_gravity_raw_get(const stmdev_ctx_t *ctx, int16_t *val);
int32_t lsm6dsv80x_sflp_quaternion_raw_get(const stmdev_ctx_t *ctx, uint16_t *val);

int32_t lsm6dsv80x_odr_cal_reg_get(const stmdev_ctx_t *ctx, int8_t *val);

int32_t lsm6dsv80x_disable_embedded_function_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_disable_embedded_function_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  uint8_t xl_hg_conv_en                : 1;
  uint8_t gyro_conv_en                 : 1;
  uint8_t temp_conv_en                 : 1;
  uint8_t ext_sensor_conv_en           : 1;
} lsm6dsv80x_emb_func_conv_t;
int32_t lsm6dsv80x_emb_func_conv_set(const stmdev_ctx_t *ctx, lsm6dsv80x_emb_func_conv_t val);
int32_t lsm6dsv80x_emb_func_conv_get(const stmdev_ctx_t *ctx, lsm6dsv80x_emb_func_conv_t *val);

int32_t lsm6dsv80x_ln_pg_write(const stmdev_ctx_t *ctx, uint16_t address,
                               uint8_t *buf, uint8_t len);
int32_t lsm6dsv80x_ln_pg_read(const stmdev_ctx_t *ctx, uint16_t address, uint8_t *buf,
                              uint8_t len);

int32_t lsm6dsv80x_emb_function_dbg_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_emb_function_dbg_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_DEN_ACT_LOW  = 0x0,
  LSM6DSV80X_DEN_ACT_HIGH = 0x1,
} lsm6dsv80x_den_polarity_t;
int32_t lsm6dsv80x_den_polarity_set(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_den_polarity_t val);
int32_t lsm6dsv80x_den_polarity_get(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_den_polarity_t *val);

int32_t lsm6dsv80x_fifo_watermark_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_fifo_watermark_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_CMP_DISABLE = 0x0,
  LSM6DSV80X_CMP_8_TO_1  = 0x1,
  LSM6DSV80X_CMP_16_TO_1 = 0x2,
  LSM6DSV80X_CMP_32_TO_1 = 0x3,
} lsm6dsv80x_fifo_compress_algo_t;
int32_t lsm6dsv80x_fifo_compress_algo_set(const stmdev_ctx_t *ctx,
                                          lsm6dsv80x_fifo_compress_algo_t val);
int32_t lsm6dsv80x_fifo_compress_algo_get(const stmdev_ctx_t *ctx,
                                          lsm6dsv80x_fifo_compress_algo_t *val);

int32_t lsm6dsv80x_fifo_virtual_sens_odr_chg_set(const stmdev_ctx_t *ctx,
                                                 uint8_t val);
int32_t lsm6dsv80x_fifo_virtual_sens_odr_chg_get(const stmdev_ctx_t *ctx,
                                                 uint8_t *val);

int32_t lsm6dsv80x_fifo_compress_algo_real_time_set(const stmdev_ctx_t *ctx,
                                                    uint8_t val);
int32_t lsm6dsv80x_fifo_compress_algo_real_time_get(const stmdev_ctx_t *ctx,
                                                    uint8_t *val);

int32_t lsm6dsv80x_fifo_stop_on_wtm_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_fifo_stop_on_wtm_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_XL_NOT_BATCHED       = 0x0,
  LSM6DSV80X_XL_BATCHED_AT_1Hz875 = 0x1,
  LSM6DSV80X_XL_BATCHED_AT_7Hz5   = 0x2,
  LSM6DSV80X_XL_BATCHED_AT_15Hz   = 0x3,
  LSM6DSV80X_XL_BATCHED_AT_30Hz   = 0x4,
  LSM6DSV80X_XL_BATCHED_AT_60Hz   = 0x5,
  LSM6DSV80X_XL_BATCHED_AT_120Hz  = 0x6,
  LSM6DSV80X_XL_BATCHED_AT_240Hz  = 0x7,
  LSM6DSV80X_XL_BATCHED_AT_480Hz  = 0x8,
  LSM6DSV80X_XL_BATCHED_AT_960Hz  = 0x9,
  LSM6DSV80X_XL_BATCHED_AT_1920Hz = 0xa,
  LSM6DSV80X_XL_BATCHED_AT_3840Hz = 0xb,
  LSM6DSV80X_XL_BATCHED_AT_7680Hz = 0xc,
} lsm6dsv80x_fifo_xl_batch_t;
int32_t lsm6dsv80x_fifo_xl_batch_set(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_fifo_xl_batch_t val);
int32_t lsm6dsv80x_fifo_xl_batch_get(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_fifo_xl_batch_t *val);

typedef enum
{
  LSM6DSV80X_GY_NOT_BATCHED       = 0x0,
  LSM6DSV80X_GY_BATCHED_AT_1Hz875 = 0x1,
  LSM6DSV80X_GY_BATCHED_AT_7Hz5   = 0x2,
  LSM6DSV80X_GY_BATCHED_AT_15Hz   = 0x3,
  LSM6DSV80X_GY_BATCHED_AT_30Hz   = 0x4,
  LSM6DSV80X_GY_BATCHED_AT_60Hz   = 0x5,
  LSM6DSV80X_GY_BATCHED_AT_120Hz  = 0x6,
  LSM6DSV80X_GY_BATCHED_AT_240Hz  = 0x7,
  LSM6DSV80X_GY_BATCHED_AT_480Hz  = 0x8,
  LSM6DSV80X_GY_BATCHED_AT_960Hz  = 0x9,
  LSM6DSV80X_GY_BATCHED_AT_1920Hz = 0xa,
  LSM6DSV80X_GY_BATCHED_AT_3840Hz = 0xb,
  LSM6DSV80X_GY_BATCHED_AT_7680Hz = 0xc,
} lsm6dsv80x_fifo_gy_batch_t;
int32_t lsm6dsv80x_fifo_gy_batch_set(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_fifo_gy_batch_t val);
int32_t lsm6dsv80x_fifo_gy_batch_get(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_fifo_gy_batch_t *val);

int32_t lsm6dsv80x_fifo_hg_xl_batch_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_fifo_hg_xl_batch_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_BYPASS_MODE             = 0x0,
  LSM6DSV80X_FIFO_MODE               = 0x1,
  LSM6DSV80X_STREAM_WTM_TO_FULL_MODE = 0x2,
  LSM6DSV80X_STREAM_TO_FIFO_MODE     = 0x3,
  LSM6DSV80X_BYPASS_TO_STREAM_MODE   = 0x4,
  LSM6DSV80X_STREAM_MODE             = 0x6,
  LSM6DSV80X_BYPASS_TO_FIFO_MODE     = 0x7,
} lsm6dsv80x_fifo_mode_t;
int32_t lsm6dsv80x_fifo_mode_set(const stmdev_ctx_t *ctx, lsm6dsv80x_fifo_mode_t val);
int32_t lsm6dsv80x_fifo_mode_get(const stmdev_ctx_t *ctx,
                                 lsm6dsv80x_fifo_mode_t *val);

typedef enum
{
  LSM6DSV80X_TEMP_NOT_BATCHED       = 0x0,
  LSM6DSV80X_TEMP_BATCHED_AT_1Hz875 = 0x1,
  LSM6DSV80X_TEMP_BATCHED_AT_15Hz   = 0x2,
  LSM6DSV80X_TEMP_BATCHED_AT_60Hz   = 0x3,
} lsm6dsv80x_fifo_temp_batch_t;
int32_t lsm6dsv80x_fifo_temp_batch_set(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_fifo_temp_batch_t val);
int32_t lsm6dsv80x_fifo_temp_batch_get(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_fifo_temp_batch_t *val);

typedef enum
{
  LSM6DSV80X_TMSTMP_NOT_BATCHED = 0x0,
  LSM6DSV80X_TMSTMP_DEC_1       = 0x1,
  LSM6DSV80X_TMSTMP_DEC_8       = 0x2,
  LSM6DSV80X_TMSTMP_DEC_32      = 0x3,
} lsm6dsv80x_fifo_timestamp_batch_t;
int32_t lsm6dsv80x_fifo_timestamp_batch_set(const stmdev_ctx_t *ctx,
                                            lsm6dsv80x_fifo_timestamp_batch_t val);
int32_t lsm6dsv80x_fifo_timestamp_batch_get(const stmdev_ctx_t *ctx,
                                            lsm6dsv80x_fifo_timestamp_batch_t *val);

int32_t lsm6dsv80x_fifo_batch_counter_threshold_set(const stmdev_ctx_t *ctx,
                                                    uint16_t val);
int32_t lsm6dsv80x_fifo_batch_counter_threshold_get(const stmdev_ctx_t *ctx,
                                                    uint16_t *val);

typedef enum
{
  LSM6DSV80X_XL_LG_BATCH_EVENT  = 0x0,
  LSM6DSV80X_GY_BATCH_EVENT     = 0x1,
  LSM6DSV80X_XL_HG_BATCH_EVENT  = 0x3,
} lsm6dsv80x_fifo_batch_cnt_event_t;
int32_t lsm6dsv80x_fifo_batch_cnt_event_set(const stmdev_ctx_t *ctx,
                                            lsm6dsv80x_fifo_batch_cnt_event_t val);
int32_t lsm6dsv80x_fifo_batch_cnt_event_get(const stmdev_ctx_t *ctx,
                                            lsm6dsv80x_fifo_batch_cnt_event_t *val);

typedef struct
{
  uint16_t fifo_level                  : 9;
  uint8_t fifo_bdr                     : 1;
  uint8_t fifo_full                    : 1;
  uint8_t fifo_ovr                     : 1;
  uint8_t fifo_th                      : 1;
} lsm6dsv80x_fifo_status_t;

int32_t lsm6dsv80x_fifo_status_get(const stmdev_ctx_t *ctx,
                                   lsm6dsv80x_fifo_status_t *val);

typedef struct
{
  enum
  {
    LSM6DSV80X_FIFO_EMPTY                    = 0x0,
    LSM6DSV80X_GY_NC_TAG                     = 0x1,
    LSM6DSV80X_XL_NC_TAG                     = 0x2,
    LSM6DSV80X_TEMPERATURE_TAG               = 0x3,
    LSM6DSV80X_TIMESTAMP_TAG                 = 0x4,
    LSM6DSV80X_CFG_CHANGE_TAG                = 0x5,
    LSM6DSV80X_XL_NC_T_2_TAG                 = 0x6,
    LSM6DSV80X_XL_NC_T_1_TAG                 = 0x7,
    LSM6DSV80X_XL_2XC_TAG                    = 0x8,
    LSM6DSV80X_XL_3XC_TAG                    = 0x9,
    LSM6DSV80X_GY_NC_T_2_TAG                 = 0xA,
    LSM6DSV80X_GY_NC_T_1_TAG                 = 0xB,
    LSM6DSV80X_GY_2XC_TAG                    = 0xC,
    LSM6DSV80X_GY_3XC_TAG                    = 0xD,
    LSM6DSV80X_SENSORHUB_TARGET0_TAG         = 0xE,
    LSM6DSV80X_SENSORHUB_TARGET1_TAG         = 0xF,
    LSM6DSV80X_SENSORHUB_TARGET2_TAG         = 0x10,
    LSM6DSV80X_SENSORHUB_TARGET3_TAG         = 0x11,
    LSM6DSV80X_STEP_COUNTER_TAG              = 0x12,
    LSM6DSV80X_SFLP_GAME_ROTATION_VECTOR_TAG = 0x13,
    LSM6DSV80X_SFLP_GYROSCOPE_BIAS_TAG       = 0x16,
    LSM6DSV80X_SFLP_GRAVITY_VECTOR_TAG       = 0x17,
    LSM6DSV80X_HG_XL_PEAK_TAG                = 0x18,
    LSM6DSV80X_SENSORHUB_NACK_TAG            = 0x19,
    LSM6DSV80X_MLC_RESULT_TAG                = 0x1A,
    LSM6DSV80X_MLC_FILTER                    = 0x1B,
    LSM6DSV80X_MLC_FEATURE                   = 0x1C,
    LSM6DSV80X_XL_HG_TAG                     = 0x1D,
    LSM6DSV80X_FSM_RESULT_TAG                = 0x1F,
  } tag;
  uint8_t cnt;
  uint8_t data[6];
} lsm6dsv80x_fifo_out_raw_t;
int32_t lsm6dsv80x_fifo_out_raw_get(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_fifo_out_raw_t *val);

int32_t lsm6dsv80x_fifo_stpcnt_batch_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_fifo_stpcnt_batch_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_fifo_fsm_batch_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_fifo_fsm_batch_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_fifo_mlc_batch_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_fifo_mlc_batch_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_fifo_mlc_filt_batch_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_fifo_mlc_filt_batch_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_fifo_sh_batch_target_set(const stmdev_ctx_t *ctx, uint8_t idx, uint8_t val);
int32_t lsm6dsv80x_fifo_sh_batch_target_get(const stmdev_ctx_t *ctx, uint8_t idx, uint8_t *val);

typedef struct
{
  uint8_t game_rotation                : 1;
  uint8_t gravity                      : 1;
  uint8_t gbias                        : 1;
} lsm6dsv80x_fifo_sflp_raw_t;
int32_t lsm6dsv80x_fifo_sflp_batch_set(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_fifo_sflp_raw_t val);
int32_t lsm6dsv80x_fifo_sflp_batch_get(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_fifo_sflp_raw_t *val);

typedef enum
{
  LSM6DSV80X_AUTO          = 0x0,
  LSM6DSV80X_ALWAYS_ACTIVE = 0x1,
} lsm6dsv80x_filt_anti_spike_t;
int32_t lsm6dsv80x_filt_anti_spike_set(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_filt_anti_spike_t val);
int32_t lsm6dsv80x_filt_anti_spike_get(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_filt_anti_spike_t *val);

typedef struct
{
  uint8_t drdy                         : 1;
  uint8_t irq_xl                       : 1;
  uint8_t irq_xl_hg                    : 1;
  uint8_t irq_g                        : 1;
} lsm6dsv80x_filt_settling_mask_t;
int32_t lsm6dsv80x_filt_settling_mask_set(const stmdev_ctx_t *ctx,
                                          lsm6dsv80x_filt_settling_mask_t val);
int32_t lsm6dsv80x_filt_settling_mask_get(const stmdev_ctx_t *ctx,
                                          lsm6dsv80x_filt_settling_mask_t *val);

typedef enum
{
  LSM6DSV80X_GY_ULTRA_LIGHT   = 0x0,
  LSM6DSV80X_GY_VERY_LIGHT    = 0x1,
  LSM6DSV80X_GY_LIGHT         = 0x2,
  LSM6DSV80X_GY_MEDIUM        = 0x3,
  LSM6DSV80X_GY_STRONG        = 0x4,
  LSM6DSV80X_GY_VERY_STRONG   = 0x5,
  LSM6DSV80X_GY_AGGRESSIVE    = 0x6,
  LSM6DSV80X_GY_XTREME        = 0x7,
} lsm6dsv80x_filt_gy_lp1_bandwidth_t;
int32_t lsm6dsv80x_filt_gy_lp1_bandwidth_set(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_filt_gy_lp1_bandwidth_t val);
int32_t lsm6dsv80x_filt_gy_lp1_bandwidth_get(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_filt_gy_lp1_bandwidth_t *val);

int32_t lsm6dsv80x_filt_gy_lp1_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_filt_gy_lp1_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_XL_ULTRA_LIGHT = 0x0,
  LSM6DSV80X_XL_VERY_LIGHT  = 0x1,
  LSM6DSV80X_XL_LIGHT       = 0x2,
  LSM6DSV80X_XL_MEDIUM      = 0x3,
  LSM6DSV80X_XL_STRONG      = 0x4,
  LSM6DSV80X_XL_VERY_STRONG = 0x5,
  LSM6DSV80X_XL_AGGRESSIVE  = 0x6,
  LSM6DSV80X_XL_XTREME      = 0x7,
} lsm6dsv80x_filt_xl_lp2_bandwidth_t;
int32_t lsm6dsv80x_filt_xl_lp2_bandwidth_set(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_filt_xl_lp2_bandwidth_t val);
int32_t lsm6dsv80x_filt_xl_lp2_bandwidth_get(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_filt_xl_lp2_bandwidth_t *val);

int32_t lsm6dsv80x_filt_xl_lp2_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_filt_xl_lp2_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_filt_xl_hp_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_filt_xl_hp_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_filt_xl_fast_settling_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_filt_xl_fast_settling_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_HP_MD_NORMAL    = 0x0,
  LSM6DSV80X_HP_MD_REFERENCE = 0x1,
} lsm6dsv80x_filt_xl_hp_mode_t;
int32_t lsm6dsv80x_filt_xl_hp_mode_set(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_filt_xl_hp_mode_t val);
int32_t lsm6dsv80x_filt_xl_hp_mode_get(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_filt_xl_hp_mode_t *val);

typedef enum
{
  LSM6DSV80X_WK_FEED_SLOPE          = 0x0,
  LSM6DSV80X_WK_FEED_HIGH_PASS      = 0x1,
  LSM6DSV80X_WK_FEED_LP_WITH_OFFSET = 0x2,
} lsm6dsv80x_filt_wkup_act_feed_t;
int32_t lsm6dsv80x_filt_wkup_act_feed_set(const stmdev_ctx_t *ctx,
                                          lsm6dsv80x_filt_wkup_act_feed_t val);
int32_t lsm6dsv80x_filt_wkup_act_feed_get(const stmdev_ctx_t *ctx,
                                          lsm6dsv80x_filt_wkup_act_feed_t *val);

int32_t lsm6dsv80x_mask_trigger_xl_settl_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_mask_trigger_xl_settl_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_SIXD_FEED_ODR_DIV_2 = 0x0,
  LSM6DSV80X_SIXD_FEED_LOW_PASS  = 0x1,
} lsm6dsv80x_filt_sixd_feed_t;
int32_t lsm6dsv80x_filt_sixd_feed_set(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_filt_sixd_feed_t val);
int32_t lsm6dsv80x_filt_sixd_feed_get(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_filt_sixd_feed_t *val);

typedef enum
{
  LSM6DSV80X_PROTECT_CTRL_REGS = 0x0,
  LSM6DSV80X_WRITE_CTRL_REG    = 0x1,
} lsm6dsv80x_fsm_permission_t;
int32_t lsm6dsv80x_fsm_permission_set(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_fsm_permission_t val);
int32_t lsm6dsv80x_fsm_permission_get(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_fsm_permission_t *val);
int32_t lsm6dsv80x_fsm_permission_status(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  uint8_t fsm1_en                      : 1;
  uint8_t fsm2_en                      : 1;
  uint8_t fsm3_en                      : 1;
  uint8_t fsm4_en                      : 1;
  uint8_t fsm5_en                      : 1;
  uint8_t fsm6_en                      : 1;
  uint8_t fsm7_en                      : 1;
  uint8_t fsm8_en                      : 1;
} lsm6dsv80x_fsm_mode_t;
int32_t lsm6dsv80x_fsm_mode_set(const stmdev_ctx_t *ctx, lsm6dsv80x_fsm_mode_t val);
int32_t lsm6dsv80x_fsm_mode_get(const stmdev_ctx_t *ctx, lsm6dsv80x_fsm_mode_t *val);

int32_t lsm6dsv80x_fsm_long_cnt_set(const stmdev_ctx_t *ctx, uint16_t val);
int32_t lsm6dsv80x_fsm_long_cnt_get(const stmdev_ctx_t *ctx, uint16_t *val);


typedef struct
{
  uint8_t fsm_outs1;
  uint8_t fsm_outs2;
  uint8_t fsm_outs3;
  uint8_t fsm_outs4;
  uint8_t fsm_outs5;
  uint8_t fsm_outs6;
  uint8_t fsm_outs7;
  uint8_t fsm_outs8;
} lsm6dsv80x_fsm_out_t;
int32_t lsm6dsv80x_fsm_out_get(const stmdev_ctx_t *ctx, lsm6dsv80x_fsm_out_t *val);

typedef enum
{
  LSM6DSV80X_FSM_15Hz  = 0x0,
  LSM6DSV80X_FSM_30Hz  = 0x1,
  LSM6DSV80X_FSM_60Hz  = 0x2,
  LSM6DSV80X_FSM_120Hz = 0x3,
  LSM6DSV80X_FSM_240Hz = 0x4,
  LSM6DSV80X_FSM_480Hz = 0x5,
  LSM6DSV80X_FSM_960Hz = 0x6,
} lsm6dsv80x_fsm_data_rate_t;
int32_t lsm6dsv80x_fsm_data_rate_set(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_fsm_data_rate_t val);
int32_t lsm6dsv80x_fsm_data_rate_get(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_fsm_data_rate_t *val);

int32_t lsm6dsv80x_fsm_ext_sens_sensitivity_set(const stmdev_ctx_t *ctx,
                                                uint16_t val);
int32_t lsm6dsv80x_fsm_ext_sens_sensitivity_get(const stmdev_ctx_t *ctx,
                                                uint16_t *val);

typedef struct
{
  uint16_t z;
  uint16_t y;
  uint16_t x;
} lsm6dsv80x_xl_fsm_ext_sens_offset_t;
int32_t lsm6dsv80x_fsm_ext_sens_offset_set(const stmdev_ctx_t *ctx,
                                           lsm6dsv80x_xl_fsm_ext_sens_offset_t val);
int32_t lsm6dsv80x_fsm_ext_sens_offset_get(const stmdev_ctx_t *ctx,
                                           lsm6dsv80x_xl_fsm_ext_sens_offset_t *val);

typedef struct
{
  uint16_t xx;
  uint16_t xy;
  uint16_t xz;
  uint16_t yy;
  uint16_t yz;
  uint16_t zz;
} lsm6dsv80x_xl_fsm_ext_sens_matrix_t;
int32_t lsm6dsv80x_fsm_ext_sens_matrix_set(const stmdev_ctx_t *ctx,
                                           lsm6dsv80x_xl_fsm_ext_sens_matrix_t val);
int32_t lsm6dsv80x_fsm_ext_sens_matrix_get(const stmdev_ctx_t *ctx,
                                           lsm6dsv80x_xl_fsm_ext_sens_matrix_t *val);

typedef enum
{
  LSM6DSV80X_Z_EQ_Y     = 0x0,
  LSM6DSV80X_Z_EQ_MIN_Y = 0x1,
  LSM6DSV80X_Z_EQ_X     = 0x2,
  LSM6DSV80X_Z_EQ_MIN_X = 0x3,
  LSM6DSV80X_Z_EQ_MIN_Z = 0x4,
  LSM6DSV80X_Z_EQ_Z     = 0x5,
} lsm6dsv80x_fsm_ext_sens_z_orient_t;
int32_t lsm6dsv80x_fsm_ext_sens_z_orient_set(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_fsm_ext_sens_z_orient_t val);
int32_t lsm6dsv80x_fsm_ext_sens_z_orient_get(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_fsm_ext_sens_z_orient_t *val);

typedef enum
{
  LSM6DSV80X_Y_EQ_Y     = 0x0,
  LSM6DSV80X_Y_EQ_MIN_Y = 0x1,
  LSM6DSV80X_Y_EQ_X     = 0x2,
  LSM6DSV80X_Y_EQ_MIN_X = 0x3,
  LSM6DSV80X_Y_EQ_MIN_Z = 0x4,
  LSM6DSV80X_Y_EQ_Z     = 0x5,
} lsm6dsv80x_fsm_ext_sens_y_orient_t;
int32_t lsm6dsv80x_fsm_ext_sens_y_orient_set(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_fsm_ext_sens_y_orient_t val);
int32_t lsm6dsv80x_fsm_ext_sens_y_orient_get(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_fsm_ext_sens_y_orient_t *val);

typedef enum
{
  LSM6DSV80X_X_EQ_Y     = 0x0,
  LSM6DSV80X_X_EQ_MIN_Y = 0x1,
  LSM6DSV80X_X_EQ_X     = 0x2,
  LSM6DSV80X_X_EQ_MIN_X = 0x3,
  LSM6DSV80X_X_EQ_MIN_Z = 0x4,
  LSM6DSV80X_X_EQ_Z     = 0x5,
} lsm6dsv80x_fsm_ext_sens_x_orient_t;
int32_t lsm6dsv80x_fsm_ext_sens_x_orient_set(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_fsm_ext_sens_x_orient_t val);
int32_t lsm6dsv80x_fsm_ext_sens_x_orient_get(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_fsm_ext_sens_x_orient_t *val);

int32_t lsm6dsv80x_xl_hg_peak_tracking_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_xl_hg_peak_tracking_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_xl_hg_sensitivity_set(const stmdev_ctx_t *ctx, uint16_t val);
int32_t lsm6dsv80x_xl_hg_sensitivity_get(const stmdev_ctx_t *ctx, uint16_t *val);

int32_t lsm6dsv80x_fsm_long_cnt_timeout_set(const stmdev_ctx_t *ctx, uint16_t val);
int32_t lsm6dsv80x_fsm_long_cnt_timeout_get(const stmdev_ctx_t *ctx, uint16_t *val);

int32_t lsm6dsv80x_fsm_number_of_programs_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_fsm_number_of_programs_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_fsm_start_address_set(const stmdev_ctx_t *ctx, uint16_t val);
int32_t lsm6dsv80x_fsm_start_address_get(const stmdev_ctx_t *ctx, uint16_t *val);

int32_t lsm6dsv80x_ff_time_windows_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_ff_time_windows_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_156_mg = 0x0,
  LSM6DSV80X_219_mg = 0x1,
  LSM6DSV80X_250_mg = 0x2,
  LSM6DSV80X_312_mg = 0x3,
  LSM6DSV80X_344_mg = 0x4,
  LSM6DSV80X_406_mg = 0x5,
  LSM6DSV80X_469_mg = 0x6,
  LSM6DSV80X_500_mg = 0x7,
} lsm6dsv80x_ff_thresholds_t;
int32_t lsm6dsv80x_ff_thresholds_set(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_ff_thresholds_t val);
int32_t lsm6dsv80x_ff_thresholds_get(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_ff_thresholds_t *val);

typedef enum
{
  LSM6DSV80X_MLC_OFF                             = 0x0,
  LSM6DSV80X_MLC_ON                              = 0x1,
  LSM6DSV80X_MLC_ON_BEFORE_FSM                   = 0x2,
} lsm6dsv80x_mlc_mode_t;
int32_t lsm6dsv80x_mlc_set(const stmdev_ctx_t *ctx, lsm6dsv80x_mlc_mode_t val);
int32_t lsm6dsv80x_mlc_get(const stmdev_ctx_t *ctx, lsm6dsv80x_mlc_mode_t *val);

typedef enum
{
  LSM6DSV80X_MLC_15Hz  = 0x0,
  LSM6DSV80X_MLC_30Hz  = 0x1,
  LSM6DSV80X_MLC_60Hz  = 0x2,
  LSM6DSV80X_MLC_120Hz = 0x3,
  LSM6DSV80X_MLC_240Hz = 0x4,
  LSM6DSV80X_MLC_480Hz = 0x5,
  LSM6DSV80X_MLC_960Hz = 0x6,
} lsm6dsv80x_mlc_data_rate_t;
int32_t lsm6dsv80x_mlc_data_rate_set(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_mlc_data_rate_t val);
int32_t lsm6dsv80x_mlc_data_rate_get(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_mlc_data_rate_t *val);

typedef struct
{
  uint8_t mlc1_src;
  uint8_t mlc2_src;
  uint8_t mlc3_src;
  uint8_t mlc4_src;
  uint8_t mlc5_src;
  uint8_t mlc6_src;
  uint8_t mlc7_src;
  uint8_t mlc8_src;
} lsm6dsv80x_mlc_out_t;
int32_t lsm6dsv80x_mlc_out_get(const stmdev_ctx_t *ctx, lsm6dsv80x_mlc_out_t *val);

int32_t lsm6dsv80x_mlc_ext_sens_sensitivity_set(const stmdev_ctx_t *ctx,
                                                uint16_t val);
int32_t lsm6dsv80x_mlc_ext_sens_sensitivity_get(const stmdev_ctx_t *ctx,
                                                uint16_t *val);

typedef enum
{
  LSM6DSV80X_DEG_80 = 0x0,
  LSM6DSV80X_DEG_70 = 0x1,
  LSM6DSV80X_DEG_60 = 0x2,
  LSM6DSV80X_DEG_50 = 0x3,
} lsm6dsv80x_6d_threshold_t;
int32_t lsm6dsv80x_6d_threshold_set(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_6d_threshold_t val);
int32_t lsm6dsv80x_6d_threshold_get(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_6d_threshold_t *val);

int32_t lsm6dsv80x_4d_mode_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_4d_mode_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_I2C_I3C_ENABLE  = 0x0,
  LSM6DSV80X_I2C_I3C_DISABLE = 0x1,
} lsm6dsv80x_ui_i2c_i3c_mode_t;
int32_t lsm6dsv80x_ui_i2c_i3c_mode_set(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_ui_i2c_i3c_mode_t val);
int32_t lsm6dsv80x_ui_i2c_i3c_mode_get(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_ui_i2c_i3c_mode_t *val);

typedef struct
{
  enum
  {
    LSM6DSV80X_SW_RST_DYN_ADDRESS_RST = 0x0,
    LSM6DSV80X_I3C_GLOBAL_RST         = 0x1,
  } rst_mode;
  enum
  {
    LSM6DSV80X_IBI_50us = 0x0,
    LSM6DSV80X_IBI_2us  = 0x1,
    LSM6DSV80X_IBI_1ms  = 0x2,
    LSM6DSV80X_IBI_50ms = 0x3,
  } ibi_time;
} lsm6dsv80x_i3c_config_t;

int32_t lsm6dsv80x_i3c_config_set(const stmdev_ctx_t *ctx,
                                  lsm6dsv80x_i3c_config_t val);
int32_t lsm6dsv80x_i3c_config_get(const stmdev_ctx_t *ctx,
                                  lsm6dsv80x_i3c_config_t *val);

int32_t lsm6dsv80x_sh_controller_interface_pull_up_set(const stmdev_ctx_t *ctx,
                                                       uint8_t val);
int32_t lsm6dsv80x_sh_controller_interface_pull_up_get(const stmdev_ctx_t *ctx,
                                                       uint8_t *val);

int32_t lsm6dsv80x_sh_read_data_raw_get(const stmdev_ctx_t *ctx, uint8_t *val,
                                        uint8_t len);

typedef enum
{
  LSM6DSV80X_TGT_0       = 0x0,
  LSM6DSV80X_TGT_0_1     = 0x1,
  LSM6DSV80X_TGT_0_1_2   = 0x2,
  LSM6DSV80X_TGT_0_1_2_3 = 0x3,
} lsm6dsv80x_sh_target_connected_t;
int32_t lsm6dsv80x_sh_target_connected_set(const stmdev_ctx_t *ctx,
                                           lsm6dsv80x_sh_target_connected_t val);
int32_t lsm6dsv80x_sh_target_connected_get(const stmdev_ctx_t *ctx,
                                           lsm6dsv80x_sh_target_connected_t *val);

int32_t lsm6dsv80x_sh_controller_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_sh_controller_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_sh_pass_through_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_sh_pass_through_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_SH_TRG_XL_GY_DRDY = 0x0,
  LSM6DSV80X_SH_TRIG_INT2      = 0x1,
} lsm6dsv80x_sh_syncro_mode_t;
int32_t lsm6dsv80x_sh_syncro_mode_set(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_sh_syncro_mode_t val);
int32_t lsm6dsv80x_sh_syncro_mode_get(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_sh_syncro_mode_t *val);

typedef enum
{
  LSM6DSV80X_EACH_SH_CYCLE    = 0x0,
  LSM6DSV80X_ONLY_FIRST_CYCLE = 0x1,
} lsm6dsv80x_sh_write_mode_t;
int32_t lsm6dsv80x_sh_write_mode_set(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_sh_write_mode_t val);
int32_t lsm6dsv80x_sh_write_mode_get(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_sh_write_mode_t *val);

int32_t lsm6dsv80x_sh_reset_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_sh_reset_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  uint8_t   tgt0_add;
  uint8_t   tgt0_subadd;
  uint8_t   tgt0_data;
} lsm6dsv80x_sh_cfg_write_t;
int32_t lsm6dsv80x_sh_cfg_write(const stmdev_ctx_t *ctx,
                                lsm6dsv80x_sh_cfg_write_t *val);
typedef enum
{
  LSM6DSV80X_SH_15Hz  = 0x1,
  LSM6DSV80X_SH_30Hz  = 0x2,
  LSM6DSV80X_SH_60Hz  = 0x3,
  LSM6DSV80X_SH_120Hz = 0x4,
  LSM6DSV80X_SH_240Hz = 0x5,
  LSM6DSV80X_SH_480Hz = 0x6,
} lsm6dsv80x_sh_data_rate_t;
int32_t lsm6dsv80x_sh_data_rate_set(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_sh_data_rate_t val);
int32_t lsm6dsv80x_sh_data_rate_get(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_sh_data_rate_t *val);

typedef struct
{
  uint8_t   tgt_add;
  uint8_t   tgt_subadd;
  uint8_t   tgt_len;
} lsm6dsv80x_sh_cfg_read_t;
int32_t lsm6dsv80x_sh_tgt_cfg_read(const stmdev_ctx_t *ctx, uint8_t idx,
                                   lsm6dsv80x_sh_cfg_read_t *val);

int32_t lsm6dsv80x_sh_status_get(const stmdev_ctx_t *ctx,
                                 lsm6dsv80x_status_controller_t *val);

int32_t lsm6dsv80x_ui_sdo_pull_up_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_ui_sdo_pull_up_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_PAD_LOW_STRENGTH     = 0x1,
  LSM6DSV80X_PAD_MIDDLE_STRENGTH  = 0x2,
  LSM6DSV80X_PAD_HIGH_STRENGTH    = 0x4,
} lsm6dsv80x_pad_strength_t;
int32_t lsm6dsv80x_pad_strength_set(const stmdev_ctx_t *ctx, lsm6dsv80x_pad_strength_t val);
int32_t lsm6dsv80x_pad_strength_get(const stmdev_ctx_t *ctx, lsm6dsv80x_pad_strength_t *val);

typedef enum
{
  LSM6DSV80X_SPI_4_WIRE = 0x0,
  LSM6DSV80X_SPI_3_WIRE = 0x1,
} lsm6dsv80x_spi_mode_t;
int32_t lsm6dsv80x_spi_mode_set(const stmdev_ctx_t *ctx, lsm6dsv80x_spi_mode_t val);
int32_t lsm6dsv80x_spi_mode_get(const stmdev_ctx_t *ctx, lsm6dsv80x_spi_mode_t *val);

int32_t lsm6dsv80x_ui_sda_pull_up_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_ui_sda_pull_up_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_if2_spi_mode_set(const stmdev_ctx_t *ctx, lsm6dsv80x_spi_mode_t val);
int32_t lsm6dsv80x_if2_spi_mode_get(const stmdev_ctx_t *ctx,
                                    lsm6dsv80x_spi_mode_t *val);

int32_t lsm6dsv80x_sigmot_mode_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_sigmot_mode_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  uint8_t step_counter_enable          : 1;
  uint8_t false_step_rej               : 1;
} lsm6dsv80x_stpcnt_mode_t;
int32_t lsm6dsv80x_stpcnt_mode_set(const stmdev_ctx_t *ctx,
                                   lsm6dsv80x_stpcnt_mode_t val);
int32_t lsm6dsv80x_stpcnt_mode_get(const stmdev_ctx_t *ctx,
                                   lsm6dsv80x_stpcnt_mode_t *val);

int32_t lsm6dsv80x_stpcnt_steps_get(const stmdev_ctx_t *ctx, uint16_t *val);

int32_t lsm6dsv80x_stpcnt_rst_step_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_stpcnt_rst_step_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_stpcnt_debounce_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_stpcnt_debounce_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_stpcnt_period_set(const stmdev_ctx_t *ctx, uint16_t val);
int32_t lsm6dsv80x_stpcnt_period_get(const stmdev_ctx_t *ctx, uint16_t *val);

int32_t lsm6dsv80x_sflp_game_rotation_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_sflp_game_rotation_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef struct
{
  float_t gbias_x; /* dps */
  float_t gbias_y; /* dps */
  float_t gbias_z; /* dps */
} lsm6dsv80x_sflp_gbias_t;
int32_t lsm6dsv80x_sflp_game_gbias_set(const stmdev_ctx_t *ctx,
                                       lsm6dsv80x_sflp_gbias_t *val);

typedef struct
{
  float_t quat_w;
  float_t quat_x;
  float_t quat_y;
  float_t quat_z;
} lsm6dsv80x_quaternion_t;
int32_t lsm6dsv80x_sflp_quaternion_get(const stmdev_ctx_t *ctx, lsm6dsv80x_quaternion_t *quat);

typedef enum
{
  LSM6DSV80X_SFLP_15Hz  = 0x0,
  LSM6DSV80X_SFLP_30Hz  = 0x1,
  LSM6DSV80X_SFLP_60Hz  = 0x2,
  LSM6DSV80X_SFLP_120Hz = 0x3,
  LSM6DSV80X_SFLP_240Hz = 0x4,
  LSM6DSV80X_SFLP_480Hz = 0x5,
} lsm6dsv80x_sflp_data_rate_t;
int32_t lsm6dsv80x_sflp_data_rate_set(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_sflp_data_rate_t val);
int32_t lsm6dsv80x_sflp_data_rate_get(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_sflp_data_rate_t *val);

typedef struct
{
  uint8_t tap_x_en                     : 1;
  uint8_t tap_y_en                     : 1;
  uint8_t tap_z_en                     : 1;
} lsm6dsv80x_tap_detection_t;
int32_t lsm6dsv80x_tap_detection_set(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_tap_detection_t val);
int32_t lsm6dsv80x_tap_detection_get(const stmdev_ctx_t *ctx,
                                     lsm6dsv80x_tap_detection_t *val);

typedef struct
{
  uint8_t x                            : 5;
  uint8_t y                            : 5;
  uint8_t z                            : 5;
} lsm6dsv80x_tap_thresholds_t;
int32_t lsm6dsv80x_tap_thresholds_set(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_tap_thresholds_t val);
int32_t lsm6dsv80x_tap_thresholds_get(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_tap_thresholds_t *val);

typedef enum
{
  LSM6DSV80X_XYZ  = 0x0,
  LSM6DSV80X_YXZ  = 0x1,
  LSM6DSV80X_XZY  = 0x2,
  LSM6DSV80X_ZYX  = 0x3,
  LSM6DSV80X_YZX  = 0x5,
  LSM6DSV80X_ZXY  = 0x6,
} lsm6dsv80x_tap_axis_priority_t;
int32_t lsm6dsv80x_tap_axis_priority_set(const stmdev_ctx_t *ctx,
                                         lsm6dsv80x_tap_axis_priority_t val);
int32_t lsm6dsv80x_tap_axis_priority_get(const stmdev_ctx_t *ctx,
                                         lsm6dsv80x_tap_axis_priority_t *val);

typedef struct
{
  uint8_t shock                        : 2;
  uint8_t quiet                        : 2;
  uint8_t tap_gap                      : 4;
} lsm6dsv80x_tap_time_windows_t;
int32_t lsm6dsv80x_tap_time_windows_set(const stmdev_ctx_t *ctx,
                                        lsm6dsv80x_tap_time_windows_t val);
int32_t lsm6dsv80x_tap_time_windows_get(const stmdev_ctx_t *ctx,
                                        lsm6dsv80x_tap_time_windows_t *val);

typedef enum
{
  LSM6DSV80X_ONLY_SINGLE        = 0x0,
  LSM6DSV80X_BOTH_SINGLE_DOUBLE = 0x1,
} lsm6dsv80x_tap_mode_t;
int32_t lsm6dsv80x_tap_mode_set(const stmdev_ctx_t *ctx, lsm6dsv80x_tap_mode_t val);
int32_t lsm6dsv80x_tap_mode_get(const stmdev_ctx_t *ctx, lsm6dsv80x_tap_mode_t *val);

int32_t lsm6dsv80x_tilt_mode_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_tilt_mode_get(const stmdev_ctx_t *ctx, uint8_t *val);

int32_t lsm6dsv80x_timestamp_raw_get(const stmdev_ctx_t *ctx, uint32_t *val);

int32_t lsm6dsv80x_timestamp_set(const stmdev_ctx_t *ctx, uint8_t val);
int32_t lsm6dsv80x_timestamp_get(const stmdev_ctx_t *ctx, uint8_t *val);

typedef enum
{
  LSM6DSV80X_XL_AND_GY_NOT_AFFECTED       = 0x0,
  LSM6DSV80X_XL_LOW_POWER_GY_NOT_AFFECTED = 0x1,
  LSM6DSV80X_XL_LOW_POWER_GY_SLEEP        = 0x2,
  LSM6DSV80X_XL_LOW_POWER_GY_POWER_DOWN   = 0x3,
} lsm6dsv80x_act_mode_t;
int32_t lsm6dsv80x_act_mode_set(const stmdev_ctx_t *ctx, lsm6dsv80x_act_mode_t val);
int32_t lsm6dsv80x_act_mode_get(const stmdev_ctx_t *ctx, lsm6dsv80x_act_mode_t *val);

typedef enum
{
  LSM6DSV80X_SLEEP_TO_ACT_AT_1ST_SAMPLE = 0x0,
  LSM6DSV80X_SLEEP_TO_ACT_AT_2ND_SAMPLE = 0x1,
  LSM6DSV80X_SLEEP_TO_ACT_AT_3RD_SAMPLE = 0x2,
  LSM6DSV80X_SLEEP_TO_ACT_AT_4th_SAMPLE = 0x3,
} lsm6dsv80x_act_from_sleep_to_act_dur_t;
int32_t lsm6dsv80x_act_from_sleep_to_act_dur_set(const stmdev_ctx_t *ctx,
                                                 lsm6dsv80x_act_from_sleep_to_act_dur_t val);
int32_t lsm6dsv80x_act_from_sleep_to_act_dur_get(const stmdev_ctx_t *ctx,
                                                 lsm6dsv80x_act_from_sleep_to_act_dur_t *val);

typedef enum
{
  LSM6DSV80X_1Hz875 = 0x0,
  LSM6DSV80X_15Hz   = 0x1,
  LSM6DSV80X_30Hz   = 0x2,
  LSM6DSV80X_60Hz   = 0x3,
} lsm6dsv80x_act_sleep_xl_odr_t;
int32_t lsm6dsv80x_act_sleep_xl_odr_set(const stmdev_ctx_t *ctx,
                                        lsm6dsv80x_act_sleep_xl_odr_t val);
int32_t lsm6dsv80x_act_sleep_xl_odr_get(const stmdev_ctx_t *ctx,
                                        lsm6dsv80x_act_sleep_xl_odr_t *val);

typedef struct
{
  lsm6dsv80x_inactivity_dur_t inactivity_cfg;
  uint8_t inactivity_ths;
  uint8_t threshold;
  uint8_t duration;
} lsm6dsv80x_act_thresholds_t;
int32_t lsm6dsv80x_act_thresholds_set(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_act_thresholds_t *val);
int32_t lsm6dsv80x_act_thresholds_get(const stmdev_ctx_t *ctx,
                                      lsm6dsv80x_act_thresholds_t *val);

typedef struct
{
  uint8_t shock                        : 2;
  uint8_t quiet                        : 4;
} lsm6dsv80x_act_wkup_time_windows_t;
int32_t lsm6dsv80x_act_wkup_time_windows_set(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_act_wkup_time_windows_t val);
int32_t lsm6dsv80x_act_wkup_time_windows_get(const stmdev_ctx_t *ctx,
                                             lsm6dsv80x_act_wkup_time_windows_t *val);

/**
  * @}
  *
  */

#ifdef __cplusplus
}
#endif

#endif /*LSM6DSV80X_DRIVER_H */
