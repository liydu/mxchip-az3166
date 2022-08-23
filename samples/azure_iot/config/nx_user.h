/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/

/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** NetX Component                                                        */
/**                                                                       */
/**   User Specific                                                       */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  PORT SPECIFIC C INFORMATION                            RELEASE        */
/*                                                                        */
/*    nx_user.h                                           PORTABLE C      */
/*                                                           6.1.11       */
/*                                                                        */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Yuxin Zhou, Microsoft Corporation                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This file contains user defines for configuring NetX in specific    */
/*    ways. This file will have an effect only if the application and     */
/*    NetX library are built with NX_INCLUDE_USER_DEFINE_FILE defined.    */
/*    Note that all the defines in this file may also be made on the      */
/*    command line when building NetX library and application objects.    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     Yuxin Zhou               Initial Version 6.0           */
/*  09-30-2020     Yuxin Zhou               Modified comment(s),          */
/*                                            resulting in version 6.1    */
/*  08-02-2021     Yuxin Zhou               Modified comment(s), and      */
/*                                            supported TCP/IP offload,   */
/*                                            resulting in version 6.1.8  */
/*  04-25-2022     Yuxin Zhou               Modified comment(s),          */
/*                                            resulting in version 6.1.11 */
/*                                                                        */
/**************************************************************************/

#ifndef NX_USER_H
#define NX_USER_H

/* Configuration options for IPv6 */

/* Disable IPv6 processing in NetX Duo.  */
#define NX_DISABLE_IPV6

/* Defined, this option enables the optional TCP immediate ACK response processing.  */
/*
#define NX_TCP_IMMEDIATE_ACK
*/

/* This define specifies the number of TCP packets to receive before sending an ACK. */
/* The default value is 2: ack every 2 packets.                                      */
/*
#define NX_TCP_ACK_EVERY_N_PACKETS  2
*/

/* Automatically define NX_TCP_ACK_EVERY_N_PACKETS to 1 if NX_TCP_IMMEDIATE_ACK is defined.
   This is needed for backward compatibility. */
// #if (defined(NX_TCP_IMMEDIATE_ACK) && !defined(NX_TCP_ACK_EVERY_N_PACKETS))
// #define NX_TCP_ACK_EVERY_N_PACKETS 1
// #endif

/* Defined, this option enables deferred driver packet handling. This allows the driver to place a raw
   packet on the IP instance and have the driver's real processing routine called from the NetX internal
   IP helper thread.  */
#define NX_DRIVER_DEFERRED_PROCESSING

/* Defined, the extended notify support is enabled.  This feature adds additional callback/notify services
   to NetX Duo API for notifying the application of socket events, such as TCP connection and disconnect
   completion.  These extended notify functions are mainly used by the BSD wrapper. The default is this
   feature is disabled.  */
#define NX_ENABLE_EXTENDED_NOTIFY_SUPPORT

/* Defined, the TCP/IP offload feature is enabled.
   NX_ENABLE_INTERFACE_CAPABILITY must be defined to enable this feature.  */
/*
#define NX_ENABLE_TCPIP_OFFLOAD
*/

/* The lowest level (highest numeric stratum level) SNTP Server stratum the
   Client will accept. The NetX Duo SNTP Client default is 2. */
#define NX_SNTP_CLIENT_MIN_SERVER_STRATUM 5

/* Define the process when assert fails. */
#define NX_ASSERT_FAIL while (1) tx_thread_sleep(NX_WAIT_FOREVER);
// extern UINT nx_rand16( void );
// #define NX_RAND                         nx_rand16

/*****************************************************************************/
/********************* Configuration options for MQTT ************************/
/*****************************************************************************/

/* Defined, MQTT Client is built with TLS support. Defining this symbol
   requires NetX Secure TLS module to be installed. NX_SECURE_ENABLE is not
   enabled by default. */
#define NX_SECURE_ENABLE

/* Defined, application must use TLS to connect to MQTT broker. This feature
   requires NX_SECURE_ENABLE defined. By default, this symbol is not
   defined. */
#define NXD_MQTT_REQUIRE_TLS

/*****************************************************************************/
/********************* Configuration options for WICED ***********************/
/*****************************************************************************/
/* Configuration options for Packet Pool */

/* This define specifies the size of the physical packet header. The default value is 16 (based on
   a typical 16-byte Ethernet header).  */
#define NX_PHYSICAL_HEADER 44

/* This define specifies the size of the physical packet trailer and is typically used to reserve storage
   for things like Ethernet CRCs, etc.  */
#define NX_PHYSICAL_TRAILER         0

/* Precision Time Protocol */
#define NX_LINK_PTP_SEND                51

#endif
