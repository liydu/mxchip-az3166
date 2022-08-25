/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#ifndef _MQTT_CONFIG_H
#define _MQTT_CONFIG_H

typedef enum
{
    None         = 0,
    WEP          = 1,
    WPA_PSK_TKIP = 2,
    WPA2_PSK_AES = 3
} WiFi_Mode;

// ----------------------------------------------------------------------------
// WiFi connection config
// ----------------------------------------------------------------------------
#define WIFI_SSID     "BabyAvocado"
#define WIFI_PASSWORD "yjy64161551"
#define WIFI_MODE     WPA2_PSK_AES

/* MQTT client configuration */
#define MQTT_BROKER_SERVER "test.mosquitto.org"
#define MQTT_TOPIC_NAME    "Temperature"
#define MQTT_NB_MESSAGE    10 /* If NB_MESSAGE = 0, client will publish messages infinitely */

#endif // _MQTT_CONFIG_H
