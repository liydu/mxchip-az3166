/* Copyright (c) Microsoft Corporation.
   Licensed under the MIT License. */

#ifndef _AZURE_DEVICE_X509_CERT_CONFIG_H
#define _AZURE_DEVICE_X509_CERT_CONFIG_H

// ----------------------------------------------------------------------------
// Azure IoT X509 Device Certificate
// Replace {0x00} with your formatted output from OpenSSL and xxd here
// ----------------------------------------------------------------------------
const unsigned char iot_x509_device_cert[] = {
  0x30, 0x82, 0x05, 0x7b, 0x30, 0x82, 0x03, 0x63, 0xa0, 0x03, 0x02, 0x01,
  0x02, 0x02, 0x10, 0x61, 0x91, 0x25, 0x88, 0xc2, 0x40, 0xbb, 0x2e, 0x61,
  0xfb, 0x3b, 0x0a, 0xda, 0x31, 0xa7, 0xb5, 0x30, 0x0d, 0x06, 0x09, 0x2a,
  0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x30, 0x34,
  0x31, 0x32, 0x30, 0x30, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x29, 0x41,
  0x7a, 0x75, 0x72, 0x65, 0x20, 0x49, 0x6f, 0x54, 0x20, 0x48, 0x75, 0x62,
  0x20, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x6d, 0x65, 0x64, 0x69, 0x61, 0x74,
  0x65, 0x20, 0x43, 0x65, 0x72, 0x74, 0x20, 0x54, 0x65, 0x73, 0x74, 0x20,
  0x4f, 0x6e, 0x6c, 0x79, 0x30, 0x1e, 0x17, 0x0d, 0x32, 0x32, 0x31, 0x30,
  0x32, 0x30, 0x30, 0x33, 0x35, 0x30, 0x35, 0x36, 0x5a, 0x17, 0x0d, 0x32,
  0x32, 0x31, 0x31, 0x31, 0x39, 0x30, 0x33, 0x35, 0x30, 0x35, 0x36, 0x5a,
  0x30, 0x14, 0x31, 0x12, 0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c,
  0x09, 0x64, 0x65, 0x76, 0x69, 0x63, 0x65, 0x2d, 0x30, 0x31, 0x30, 0x82,
  0x02, 0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d,
  0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x02, 0x0f, 0x00, 0x30, 0x82,
  0x02, 0x0a, 0x02, 0x82, 0x02, 0x01, 0x00, 0xe0, 0x67, 0x5a, 0xf1, 0x3a,
  0x73, 0x21, 0x98, 0xdd, 0x5e, 0x37, 0xa9, 0x67, 0x90, 0x95, 0x6c, 0x64,
  0x67, 0xd8, 0xa5, 0xaa, 0xfc, 0xb8, 0x50, 0x88, 0x30, 0xf3, 0x8f, 0x7c,
  0x0c, 0x20, 0x51, 0xac, 0x5c, 0x9f, 0x16, 0x1b, 0x7e, 0x19, 0x11, 0x8b,
  0x32, 0xe6, 0xfe, 0x92, 0xb1, 0xf7, 0x2f, 0x8b, 0x40, 0xc6, 0xfa, 0xca,
  0xe9, 0x97, 0xce, 0x94, 0xbd, 0x11, 0x43, 0xf9, 0x45, 0xc2, 0xec, 0x04,
  0x8d, 0x2c, 0x15, 0xdf, 0xd0, 0x15, 0xfa, 0x24, 0xbc, 0x2b, 0x34, 0x79,
  0xf3, 0x43, 0xb4, 0x0a, 0xd3, 0x52, 0xe1, 0x6c, 0x22, 0xbb, 0xee, 0x77,
  0x97, 0x08, 0xbf, 0xb5, 0xe3, 0x57, 0xfe, 0x49, 0x37, 0x5f, 0x7a, 0x76,
  0x19, 0x56, 0x1b, 0xc2, 0x8e, 0x39, 0x65, 0x37, 0xd2, 0xf6, 0xd5, 0x92,
  0x25, 0xd2, 0x6d, 0xee, 0x6b, 0x77, 0x83, 0x96, 0x48, 0x6d, 0xc1, 0xd9,
  0x32, 0xf2, 0x8f, 0xd6, 0x1c, 0xe3, 0x0f, 0x4c, 0x7c, 0x37, 0xa9, 0xb6,
  0x66, 0x7f, 0xc5, 0xd3, 0x1e, 0x14, 0x63, 0x3a, 0x5a, 0xa7, 0xf8, 0xa7,
  0x75, 0xf3, 0x03, 0x35, 0x55, 0x0e, 0xf1, 0x2a, 0xf8, 0x18, 0x7c, 0xe9,
  0x22, 0x77, 0x96, 0x11, 0xff, 0x8d, 0x30, 0x48, 0x72, 0x4a, 0x91, 0xc1,
  0xbe, 0x86, 0x5b, 0x80, 0x53, 0x5d, 0xa5, 0x7b, 0xa2, 0xd9, 0xc9, 0x39,
  0xc3, 0x38, 0xd7, 0x11, 0xd5, 0xc1, 0x23, 0x93, 0x49, 0x1e, 0x31, 0xee,
  0x9c, 0x40, 0x5b, 0xb7, 0xf5, 0x6f, 0xf8, 0x3f, 0xb9, 0x5a, 0xaf, 0x23,
  0xab, 0xd9, 0x5e, 0xe8, 0x30, 0x35, 0xdd, 0x2d, 0xf5, 0x6e, 0xbb, 0xeb,
  0x5e, 0x68, 0x8e, 0x8a, 0x82, 0x94, 0x23, 0x8c, 0xdf, 0x34, 0x2b, 0x1d,
  0x10, 0x46, 0x3e, 0x70, 0x98, 0x78, 0x8d, 0xfb, 0xf1, 0xea, 0x28, 0x46,
  0x13, 0xb0, 0x68, 0x49, 0xde, 0x8b, 0x4d, 0x22, 0xeb, 0x29, 0x17, 0x15,
  0xe8, 0x22, 0xd2, 0x46, 0x3c, 0xc0, 0xfb, 0x28, 0x5f, 0xf7, 0x59, 0xbc,
  0x5f, 0xac, 0x6c, 0xea, 0x8e, 0x4e, 0xbe, 0xba, 0x5b, 0x6f, 0xe9, 0x7a,
  0x76, 0xf9, 0x6c, 0x8f, 0x50, 0x8d, 0x59, 0xd8, 0x9c, 0x98, 0x24, 0x87,
  0x41, 0x8e, 0xf1, 0x69, 0xc1, 0x32, 0x2a, 0x7c, 0x0c, 0x11, 0x59, 0x88,
  0x97, 0x00, 0x9a, 0x37, 0x5f, 0x2b, 0x46, 0x19, 0x99, 0xcf, 0x54, 0x91,
  0x9d, 0xd3, 0x30, 0x3e, 0x89, 0xb6, 0xef, 0x38, 0xc7, 0x20, 0x79, 0xf8,
  0x39, 0x23, 0x64, 0x60, 0x77, 0xfa, 0x4b, 0xf7, 0x1a, 0xd2, 0xcd, 0x92,
  0x8b, 0xb6, 0x41, 0x89, 0x8d, 0x48, 0xc8, 0x00, 0x44, 0x19, 0x1a, 0xb7,
  0x1e, 0x96, 0x0a, 0xe8, 0x29, 0x81, 0x14, 0x9b, 0x4f, 0x87, 0x62, 0xc8,
  0xd4, 0xac, 0xe2, 0x35, 0x02, 0xce, 0x78, 0x74, 0x65, 0x3f, 0x88, 0x4a,
  0x03, 0x63, 0x93, 0x24, 0x34, 0xd1, 0xbf, 0x05, 0xcd, 0x6f, 0x38, 0xc5,
  0x08, 0x26, 0xca, 0xe5, 0x5f, 0x72, 0xcd, 0x7d, 0x71, 0xbe, 0x9e, 0xf8,
  0x97, 0x68, 0x3c, 0x18, 0xc4, 0x6d, 0x94, 0xd9, 0x12, 0x7e, 0x7a, 0x25,
  0xe7, 0xa7, 0xe5, 0x24, 0x90, 0x38, 0x47, 0x43, 0x0d, 0xc8, 0x9e, 0x35,
  0xf2, 0x9a, 0x88, 0x9d, 0xd1, 0x05, 0xca, 0x56, 0x8a, 0x1d, 0x18, 0x69,
  0x44, 0x9b, 0xc0, 0xec, 0x64, 0x18, 0x11, 0x40, 0x99, 0x39, 0x29, 0xe2,
  0x37, 0xaf, 0x88, 0xd3, 0x02, 0xae, 0x91, 0x39, 0xd9, 0xed, 0x31, 0x3c,
  0x89, 0x0f, 0x74, 0xfb, 0x8a, 0xe4, 0xd4, 0xa6, 0x5c, 0xd9, 0x60, 0x13,
  0x8e, 0x89, 0x6c, 0xc8, 0xc1, 0xb4, 0x74, 0x98, 0x2f, 0xa4, 0x12, 0x32,
  0x0e, 0xf8, 0x9f, 0xbd, 0x74, 0x7e, 0xa3, 0xd7, 0xee, 0xc1, 0x21, 0x76,
  0x90, 0xa1, 0x17, 0x35, 0xc9, 0x39, 0x72, 0x13, 0xb0, 0xc2, 0xcb, 0x41,
  0x05, 0x55, 0xe3, 0x02, 0x03, 0x01, 0x00, 0x01, 0xa3, 0x81, 0xa8, 0x30,
  0x81, 0xa5, 0x30, 0x09, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x04, 0x02, 0x30,
  0x00, 0x30, 0x33, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x86, 0xf8, 0x42,
  0x01, 0x0d, 0x04, 0x26, 0x16, 0x24, 0x4f, 0x70, 0x65, 0x6e, 0x53, 0x53,
  0x4c, 0x20, 0x47, 0x65, 0x6e, 0x65, 0x72, 0x61, 0x74, 0x65, 0x64, 0x20,
  0x43, 0x6c, 0x69, 0x65, 0x6e, 0x74, 0x20, 0x43, 0x65, 0x72, 0x74, 0x69,
  0x66, 0x69, 0x63, 0x61, 0x74, 0x65, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d,
  0x0e, 0x04, 0x16, 0x04, 0x14, 0x14, 0x6a, 0x74, 0x18, 0xdb, 0xb3, 0xd5,
  0x20, 0xe8, 0x91, 0xa6, 0x2d, 0xc3, 0xc1, 0x3a, 0x40, 0xc6, 0xc0, 0x53,
  0x42, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30, 0x16,
  0x80, 0x14, 0xc8, 0x52, 0x94, 0x7c, 0x09, 0x18, 0x2a, 0xbc, 0x7a, 0xc7,
  0x2a, 0xf6, 0x57, 0x7e, 0x45, 0x25, 0x78, 0xe2, 0x1a, 0x3a, 0x30, 0x0e,
  0x06, 0x03, 0x55, 0x1d, 0x0f, 0x01, 0x01, 0xff, 0x04, 0x04, 0x03, 0x02,
  0x05, 0xe0, 0x30, 0x13, 0x06, 0x03, 0x55, 0x1d, 0x25, 0x04, 0x0c, 0x30,
  0x0a, 0x06, 0x08, 0x2b, 0x06, 0x01, 0x05, 0x05, 0x07, 0x03, 0x02, 0x30,
  0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b,
  0x05, 0x00, 0x03, 0x82, 0x02, 0x01, 0x00, 0xa0, 0xa1, 0x00, 0x63, 0x1b,
  0x52, 0x27, 0xa6, 0x05, 0x54, 0x85, 0x1e, 0xbb, 0x3a, 0xe5, 0x0b, 0x36,
  0x9e, 0x66, 0x12, 0xc2, 0xaf, 0xbd, 0x40, 0x73, 0x08, 0x30, 0x11, 0x0a,
  0x32, 0xf7, 0x1b, 0xb9, 0x3c, 0xbf, 0xb1, 0xe0, 0x1d, 0x86, 0x55, 0x2e,
  0x28, 0x85, 0x16, 0x67, 0xae, 0x4b, 0x57, 0x3b, 0x08, 0xa3, 0x68, 0xb2,
  0x89, 0x65, 0x00, 0x93, 0x66, 0x19, 0xc1, 0xf1, 0x10, 0xcb, 0x31, 0xd6,
  0x17, 0x83, 0xee, 0xbf, 0xc4, 0x2b, 0x59, 0xef, 0x4f, 0x3d, 0x72, 0xb5,
  0xfb, 0x9f, 0xeb, 0x8e, 0x93, 0xbb, 0x50, 0x86, 0x55, 0x4a, 0x70, 0x93,
  0xa4, 0x1f, 0x93, 0xd7, 0xec, 0x66, 0x86, 0x03, 0x2d, 0x62, 0x30, 0x37,
  0x36, 0x04, 0x57, 0x6c, 0xfd, 0x4e, 0xd2, 0xe9, 0xbd, 0x7f, 0xc7, 0xdb,
  0x80, 0xdb, 0xe8, 0xfe, 0x74, 0x00, 0xdc, 0x7b, 0x53, 0x85, 0x10, 0xb3,
  0x8e, 0xa5, 0x81, 0x5a, 0x4d, 0x1b, 0xf3, 0x26, 0xc9, 0x6b, 0xfe, 0x82,
  0x6a, 0xa5, 0xa1, 0x97, 0x2d, 0xd6, 0xe7, 0xc7, 0xf2, 0xe9, 0xb2, 0x4a,
  0x56, 0x5d, 0x9f, 0x56, 0x69, 0x5e, 0xc9, 0xd8, 0x48, 0x92, 0x61, 0x4d,
  0xdc, 0x05, 0x54, 0x82, 0xc6, 0x03, 0x10, 0x13, 0xdd, 0x7e, 0xf4, 0xd1,
  0x77, 0x6d, 0x85, 0x1a, 0x43, 0x7c, 0x07, 0x59, 0x32, 0x55, 0x3d, 0xae,
  0x29, 0x9f, 0x77, 0xcf, 0xb7, 0xff, 0xcb, 0x40, 0x8e, 0x0f, 0x45, 0x7d,
  0x06, 0x7f, 0x6e, 0x51, 0x6b, 0x49, 0x34, 0xbe, 0x75, 0x34, 0x8e, 0x70,
  0xf4, 0x39, 0x29, 0xd7, 0xcb, 0xd0, 0xbb, 0x7c, 0x07, 0xf9, 0xbd, 0x4f,
  0x46, 0xb1, 0x40, 0x6d, 0xe9, 0x12, 0x62, 0xe4, 0xec, 0x08, 0xc9, 0xd2,
  0x61, 0xaa, 0xdf, 0xbd, 0x9d, 0x78, 0xf3, 0xf1, 0xc2, 0xd8, 0x05, 0xf3,
  0xfe, 0xba, 0x75, 0xdc, 0x93, 0xa4, 0x6e, 0x9b, 0x8d, 0x49, 0x1b, 0xdb,
  0x4e, 0x01, 0x6f, 0x4c, 0x8b, 0x21, 0x3b, 0x88, 0x8c, 0xae, 0xf3, 0xe3,
  0xfe, 0x16, 0x47, 0x84, 0x15, 0xe2, 0x86, 0x02, 0xd4, 0xa1, 0xb7, 0xd4,
  0xf1, 0xa1, 0x6d, 0x06, 0xd3, 0xf1, 0xd5, 0x6f, 0x3a, 0x37, 0xe6, 0x61,
  0x5f, 0xea, 0xc8, 0xf4, 0xb0, 0xab, 0x05, 0x3f, 0xa7, 0x7e, 0x57, 0x9d,
  0x43, 0xdd, 0x7f, 0x9e, 0xe5, 0x42, 0x28, 0x0e, 0x85, 0xa6, 0x29, 0x72,
  0xa9, 0x82, 0xdc, 0x6c, 0xbe, 0x76, 0x22, 0xa0, 0x64, 0x88, 0xff, 0x8f,
  0x12, 0xd2, 0xaa, 0x1e, 0xa0, 0xc3, 0x86, 0xde, 0xef, 0xc9, 0xd2, 0x05,
  0x93, 0xbc, 0xba, 0xd9, 0x4c, 0x69, 0x8d, 0xe5, 0x79, 0x9b, 0xfc, 0x93,
  0xf1, 0x0a, 0x96, 0x06, 0x1e, 0xa0, 0x1c, 0xa9, 0x5f, 0x00, 0xde, 0x36,
  0x09, 0x5f, 0x6f, 0x22, 0xe9, 0x56, 0xe6, 0x83, 0xe4, 0xd6, 0x99, 0x17,
  0xd0, 0x6a, 0xdf, 0x82, 0x00, 0x6e, 0x52, 0x7f, 0x16, 0x20, 0xc8, 0xf4,
  0x83, 0x6b, 0xfd, 0x85, 0x7a, 0xb8, 0x3d, 0x40, 0x60, 0x91, 0xfe, 0x5d,
  0x07, 0xd8, 0x1b, 0xdd, 0xcc, 0x07, 0x11, 0x38, 0xe7, 0xf0, 0xf0, 0xa8,
  0xb4, 0xa8, 0x0f, 0x97, 0x68, 0x2d, 0x0c, 0x1b, 0xb1, 0xeb, 0xe6, 0xe8,
  0xae, 0x37, 0x6d, 0xd7, 0x62, 0xb4, 0x56, 0xe0, 0x6c, 0x8d, 0x66, 0xae,
  0x9f, 0xb3, 0x8a, 0x8b, 0xbf, 0x90, 0xdb, 0x8c, 0xca, 0x30, 0x5a, 0xc1,
  0xf7, 0x4b, 0x1d, 0xff, 0xb6, 0x83, 0x7c, 0x67, 0x52, 0x0b, 0x34, 0xa2,
  0x15, 0x00, 0x02, 0x05, 0x26, 0xec, 0x54, 0xef, 0x07, 0xa1, 0xae, 0x60,
  0x31, 0x33, 0x02, 0xc1, 0xc0, 0x33, 0x2b, 0xbf, 0x33, 0xd0, 0x2a, 0xb2,
  0xd1, 0x6d, 0xbc, 0x1a, 0x7b, 0xbf, 0x78, 0xa6, 0x23, 0x21, 0x27, 0xae,
  0x68, 0xbb, 0x47, 0x8c, 0xff, 0xa3, 0x44, 0x83, 0x1c, 0x79, 0x81, 0x00,
  0x05, 0xb4, 0xcc
};
// unsigned int iot_x509_device_cert_len = sizeof(iot_x509_device_cert);
unsigned int iot_x509_device_cert_len = 1407;

// ----------------------------------------------------------------------------
// Azure IoT X509 Device Private Key
// Replace {0x00} with your formatted output from OpenSSL and xxd here
// ----------------------------------------------------------------------------
unsigned char iot_x509_private_key[] = {
  0x30, 0x82, 0x09, 0x42, 0x02, 0x01, 0x00, 0x30, 0x0d, 0x06, 0x09, 0x2a,
  0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82,
  0x09, 0x2c, 0x30, 0x82, 0x09, 0x28, 0x02, 0x01, 0x00, 0x02, 0x82, 0x02,
  0x01, 0x00, 0xe0, 0x67, 0x5a, 0xf1, 0x3a, 0x73, 0x21, 0x98, 0xdd, 0x5e,
  0x37, 0xa9, 0x67, 0x90, 0x95, 0x6c, 0x64, 0x67, 0xd8, 0xa5, 0xaa, 0xfc,
  0xb8, 0x50, 0x88, 0x30, 0xf3, 0x8f, 0x7c, 0x0c, 0x20, 0x51, 0xac, 0x5c,
  0x9f, 0x16, 0x1b, 0x7e, 0x19, 0x11, 0x8b, 0x32, 0xe6, 0xfe, 0x92, 0xb1,
  0xf7, 0x2f, 0x8b, 0x40, 0xc6, 0xfa, 0xca, 0xe9, 0x97, 0xce, 0x94, 0xbd,
  0x11, 0x43, 0xf9, 0x45, 0xc2, 0xec, 0x04, 0x8d, 0x2c, 0x15, 0xdf, 0xd0,
  0x15, 0xfa, 0x24, 0xbc, 0x2b, 0x34, 0x79, 0xf3, 0x43, 0xb4, 0x0a, 0xd3,
  0x52, 0xe1, 0x6c, 0x22, 0xbb, 0xee, 0x77, 0x97, 0x08, 0xbf, 0xb5, 0xe3,
  0x57, 0xfe, 0x49, 0x37, 0x5f, 0x7a, 0x76, 0x19, 0x56, 0x1b, 0xc2, 0x8e,
  0x39, 0x65, 0x37, 0xd2, 0xf6, 0xd5, 0x92, 0x25, 0xd2, 0x6d, 0xee, 0x6b,
  0x77, 0x83, 0x96, 0x48, 0x6d, 0xc1, 0xd9, 0x32, 0xf2, 0x8f, 0xd6, 0x1c,
  0xe3, 0x0f, 0x4c, 0x7c, 0x37, 0xa9, 0xb6, 0x66, 0x7f, 0xc5, 0xd3, 0x1e,
  0x14, 0x63, 0x3a, 0x5a, 0xa7, 0xf8, 0xa7, 0x75, 0xf3, 0x03, 0x35, 0x55,
  0x0e, 0xf1, 0x2a, 0xf8, 0x18, 0x7c, 0xe9, 0x22, 0x77, 0x96, 0x11, 0xff,
  0x8d, 0x30, 0x48, 0x72, 0x4a, 0x91, 0xc1, 0xbe, 0x86, 0x5b, 0x80, 0x53,
  0x5d, 0xa5, 0x7b, 0xa2, 0xd9, 0xc9, 0x39, 0xc3, 0x38, 0xd7, 0x11, 0xd5,
  0xc1, 0x23, 0x93, 0x49, 0x1e, 0x31, 0xee, 0x9c, 0x40, 0x5b, 0xb7, 0xf5,
  0x6f, 0xf8, 0x3f, 0xb9, 0x5a, 0xaf, 0x23, 0xab, 0xd9, 0x5e, 0xe8, 0x30,
  0x35, 0xdd, 0x2d, 0xf5, 0x6e, 0xbb, 0xeb, 0x5e, 0x68, 0x8e, 0x8a, 0x82,
  0x94, 0x23, 0x8c, 0xdf, 0x34, 0x2b, 0x1d, 0x10, 0x46, 0x3e, 0x70, 0x98,
  0x78, 0x8d, 0xfb, 0xf1, 0xea, 0x28, 0x46, 0x13, 0xb0, 0x68, 0x49, 0xde,
  0x8b, 0x4d, 0x22, 0xeb, 0x29, 0x17, 0x15, 0xe8, 0x22, 0xd2, 0x46, 0x3c,
  0xc0, 0xfb, 0x28, 0x5f, 0xf7, 0x59, 0xbc, 0x5f, 0xac, 0x6c, 0xea, 0x8e,
  0x4e, 0xbe, 0xba, 0x5b, 0x6f, 0xe9, 0x7a, 0x76, 0xf9, 0x6c, 0x8f, 0x50,
  0x8d, 0x59, 0xd8, 0x9c, 0x98, 0x24, 0x87, 0x41, 0x8e, 0xf1, 0x69, 0xc1,
  0x32, 0x2a, 0x7c, 0x0c, 0x11, 0x59, 0x88, 0x97, 0x00, 0x9a, 0x37, 0x5f,
  0x2b, 0x46, 0x19, 0x99, 0xcf, 0x54, 0x91, 0x9d, 0xd3, 0x30, 0x3e, 0x89,
  0xb6, 0xef, 0x38, 0xc7, 0x20, 0x79, 0xf8, 0x39, 0x23, 0x64, 0x60, 0x77,
  0xfa, 0x4b, 0xf7, 0x1a, 0xd2, 0xcd, 0x92, 0x8b, 0xb6, 0x41, 0x89, 0x8d,
  0x48, 0xc8, 0x00, 0x44, 0x19, 0x1a, 0xb7, 0x1e, 0x96, 0x0a, 0xe8, 0x29,
  0x81, 0x14, 0x9b, 0x4f, 0x87, 0x62, 0xc8, 0xd4, 0xac, 0xe2, 0x35, 0x02,
  0xce, 0x78, 0x74, 0x65, 0x3f, 0x88, 0x4a, 0x03, 0x63, 0x93, 0x24, 0x34,
  0xd1, 0xbf, 0x05, 0xcd, 0x6f, 0x38, 0xc5, 0x08, 0x26, 0xca, 0xe5, 0x5f,
  0x72, 0xcd, 0x7d, 0x71, 0xbe, 0x9e, 0xf8, 0x97, 0x68, 0x3c, 0x18, 0xc4,
  0x6d, 0x94, 0xd9, 0x12, 0x7e, 0x7a, 0x25, 0xe7, 0xa7, 0xe5, 0x24, 0x90,
  0x38, 0x47, 0x43, 0x0d, 0xc8, 0x9e, 0x35, 0xf2, 0x9a, 0x88, 0x9d, 0xd1,
  0x05, 0xca, 0x56, 0x8a, 0x1d, 0x18, 0x69, 0x44, 0x9b, 0xc0, 0xec, 0x64,
  0x18, 0x11, 0x40, 0x99, 0x39, 0x29, 0xe2, 0x37, 0xaf, 0x88, 0xd3, 0x02,
  0xae, 0x91, 0x39, 0xd9, 0xed, 0x31, 0x3c, 0x89, 0x0f, 0x74, 0xfb, 0x8a,
  0xe4, 0xd4, 0xa6, 0x5c, 0xd9, 0x60, 0x13, 0x8e, 0x89, 0x6c, 0xc8, 0xc1,
  0xb4, 0x74, 0x98, 0x2f, 0xa4, 0x12, 0x32, 0x0e, 0xf8, 0x9f, 0xbd, 0x74,
  0x7e, 0xa3, 0xd7, 0xee, 0xc1, 0x21, 0x76, 0x90, 0xa1, 0x17, 0x35, 0xc9,
  0x39, 0x72, 0x13, 0xb0, 0xc2, 0xcb, 0x41, 0x05, 0x55, 0xe3, 0x02, 0x03,
  0x01, 0x00, 0x01, 0x02, 0x82, 0x02, 0x00, 0x0e, 0x9e, 0x0c, 0xe9, 0x7b,
  0xc2, 0x36, 0x25, 0x0b, 0xfe, 0x70, 0x27, 0xc3, 0xcc, 0x42, 0x3f, 0x7e,
  0x46, 0xd9, 0x70, 0xe9, 0x33, 0x6f, 0x1a, 0x27, 0xd4, 0xf0, 0x78, 0x9f,
  0x3e, 0xf6, 0xf7, 0xfa, 0xff, 0x49, 0x89, 0x9a, 0x1e, 0xdb, 0xa9, 0x2d,
  0xe5, 0x11, 0xf0, 0xf1, 0x43, 0x50, 0x73, 0xb3, 0x61, 0x73, 0xd4, 0xb0,
  0x55, 0x09, 0x03, 0x76, 0xe2, 0xdd, 0xf6, 0x0c, 0x8d, 0xc3, 0xc5, 0xb6,
  0x02, 0x30, 0x25, 0xf8, 0x9f, 0x48, 0x5f, 0x33, 0xf7, 0x61, 0xe5, 0x18,
  0x30, 0x85, 0x6f, 0x7b, 0xe9, 0x0a, 0x14, 0x0f, 0x04, 0x30, 0x33, 0xb7,
  0x6c, 0x8a, 0x30, 0x5a, 0xbb, 0xc5, 0x66, 0x96, 0x04, 0x5a, 0x5e, 0xd2,
  0xc4, 0x91, 0xbc, 0x5b, 0x2f, 0x02, 0x84, 0x1a, 0x5f, 0xce, 0x9e, 0x58,
  0xd7, 0xc7, 0xde, 0x4b, 0x52, 0x8a, 0xc5, 0x72, 0x8b, 0xa3, 0x42, 0xa6,
  0x50, 0x50, 0x46, 0x98, 0x4e, 0xe7, 0x67, 0x7e, 0xb6, 0xf4, 0xb5, 0x44,
  0x61, 0x66, 0xdf, 0x4f, 0x02, 0x3d, 0x97, 0xbd, 0x1c, 0x5c, 0xa6, 0xb0,
  0xd9, 0xd9, 0x0b, 0x93, 0x74, 0xc7, 0xf5, 0x63, 0xb4, 0x27, 0x7c, 0x33,
  0x7f, 0x80, 0x44, 0xb1, 0x45, 0x71, 0x3f, 0xfc, 0xe8, 0x1c, 0xfd, 0x63,
  0x9e, 0x72, 0x88, 0x11, 0x52, 0xdc, 0xdd, 0xc3, 0xb0, 0xf6, 0xf8, 0xc9,
  0x9f, 0x72, 0xdb, 0x67, 0x99, 0x01, 0xec, 0xbc, 0x52, 0x5d, 0xfa, 0x28,
  0xad, 0xda, 0xef, 0x5e, 0x8b, 0x49, 0x50, 0xe5, 0x6d, 0xc0, 0x7f, 0x7a,
  0x16, 0x5e, 0xa1, 0x75, 0x04, 0x76, 0xed, 0xc2, 0x69, 0xa3, 0x5d, 0xf0,
  0x56, 0x04, 0xff, 0x8b, 0xfc, 0x37, 0x84, 0x1d, 0x50, 0x08, 0xc8, 0xea,
  0x2a, 0xbe, 0x38, 0xa1, 0x02, 0xfd, 0x8f, 0x5a, 0x23, 0x06, 0xfa, 0xba,
  0x9d, 0xdb, 0xb6, 0xdf, 0x60, 0xf4, 0xb8, 0x00, 0x97, 0x4a, 0xe4, 0xcb,
  0xd9, 0x59, 0x94, 0x9b, 0x14, 0x5c, 0xe8, 0x27, 0x14, 0x43, 0x31, 0x0a,
  0xfd, 0xa7, 0xa1, 0x61, 0x25, 0x1c, 0x92, 0x33, 0x00, 0x5c, 0xee, 0x4e,
  0x97, 0x33, 0xda, 0x43, 0x5e, 0xd5, 0xc2, 0xd9, 0x93, 0xfc, 0xa9, 0x78,
  0xbb, 0x6e, 0xd0, 0x0a, 0xa4, 0xe3, 0x45, 0x02, 0xaa, 0xb8, 0x5b, 0xf8,
  0xca, 0x77, 0xbd, 0x67, 0x31, 0x7f, 0xe7, 0xea, 0x98, 0x97, 0x0c, 0x07,
  0x4f, 0xc1, 0xbd, 0xea, 0x4e, 0x78, 0xf3, 0x6e, 0x5c, 0x86, 0xc4, 0xde,
  0x36, 0xa9, 0xf0, 0x25, 0x5d, 0x52, 0x5f, 0x5c, 0xf6, 0x40, 0x59, 0xf7,
  0x77, 0xa2, 0xd4, 0x37, 0xd4, 0x07, 0x33, 0xe9, 0x17, 0x6c, 0xc6, 0x08,
  0xc6, 0xae, 0x6f, 0x84, 0x5f, 0xa9, 0x56, 0x3c, 0x1c, 0xa1, 0xec, 0xca,
  0x13, 0x98, 0x94, 0x8e, 0x16, 0xcc, 0xc8, 0x07, 0xe8, 0x8f, 0xcd, 0x7b,
  0xcb, 0xc0, 0x66, 0x6b, 0x9c, 0x9b, 0xf5, 0xac, 0x4e, 0x8c, 0x59, 0x44,
  0xf7, 0xb1, 0x86, 0x03, 0xf8, 0x27, 0x86, 0xf7, 0xfd, 0xab, 0xe3, 0xb5,
  0x9d, 0xb5, 0x3f, 0xa2, 0xa8, 0xfe, 0x35, 0x10, 0x7f, 0x5c, 0x2e, 0x6a,
  0x3f, 0x69, 0xee, 0x60, 0x16, 0x60, 0x5c, 0x2b, 0xea, 0x23, 0x03, 0x81,
  0x7d, 0xc0, 0x86, 0x68, 0xd5, 0x08, 0x8e, 0xcb, 0xd5, 0xb4, 0x82, 0x9f,
  0xcb, 0xa4, 0x04, 0x2e, 0xd6, 0xe0, 0x1e, 0x56, 0xd8, 0xb8, 0x92, 0x42,
  0x77, 0x54, 0xbc, 0x09, 0x78, 0x85, 0xd1, 0x8c, 0x86, 0xf5, 0x35, 0x3b,
  0x97, 0x09, 0xbd, 0x4b, 0x95, 0x30, 0xf0, 0xc0, 0x8e, 0xec, 0x74, 0x68,
  0xe5, 0xc8, 0xcb, 0xa9, 0xfe, 0x72, 0xc9, 0x59, 0xf0, 0xcf, 0xcd, 0xfe,
  0x0e, 0xb9, 0x8e, 0x21, 0x75, 0x81, 0x87, 0x50, 0x3c, 0x90, 0x5b, 0x75,
  0xbc, 0x26, 0x3b, 0xc2, 0x65, 0x2d, 0x8f, 0xc3, 0x4c, 0x53, 0xb5, 0x04,
  0x41, 0x9c, 0xa9, 0x02, 0x82, 0x01, 0x01, 0x00, 0xed, 0x48, 0x40, 0xc6,
  0x52, 0x1d, 0x2b, 0xa6, 0x7c, 0x1e, 0xdd, 0x17, 0xc6, 0x08, 0xe7, 0x8d,
  0x18, 0x15, 0x99, 0x96, 0x49, 0xdc, 0x09, 0xee, 0xd2, 0x52, 0x5e, 0x77,
  0x85, 0xfa, 0x48, 0xe9, 0xe0, 0x8e, 0x47, 0xd1, 0x19, 0xf1, 0xb0, 0x81,
  0x47, 0xb6, 0xe9, 0x94, 0x67, 0x8a, 0xc6, 0x58, 0xc8, 0x5a, 0x53, 0xb6,
  0x82, 0xf3, 0xb1, 0xb5, 0x74, 0x0f, 0xcb, 0x14, 0x61, 0x80, 0x48, 0x3f,
  0xfa, 0xc9, 0xd3, 0x40, 0xcc, 0x7d, 0x1d, 0x70, 0xc8, 0x3d, 0xdd, 0x3b,
  0xd3, 0x27, 0xfc, 0x4d, 0x5e, 0xab, 0xaf, 0x5a, 0x45, 0x78, 0x63, 0xb0,
  0xe8, 0x9f, 0x28, 0x8a, 0x02, 0x77, 0x61, 0xab, 0x47, 0xf6, 0xc5, 0x82,
  0x8c, 0x24, 0x6f, 0x53, 0xca, 0x27, 0x5c, 0x88, 0xa7, 0xb2, 0x5b, 0x29,
  0xa5, 0xfe, 0xd4, 0xb2, 0x3b, 0x3f, 0x35, 0xe5, 0xd1, 0x55, 0x8e, 0xa7,
  0x15, 0x3d, 0x73, 0x5e, 0xbb, 0x69, 0xfe, 0x05, 0x74, 0x74, 0xe5, 0x1d,
  0xf7, 0xfd, 0xd2, 0x67, 0xf7, 0x52, 0xd3, 0x6d, 0x7f, 0x05, 0x7c, 0x64,
  0x62, 0x24, 0xfc, 0x9c, 0x44, 0x2c, 0x46, 0x14, 0x2a, 0x4f, 0x73, 0x1c,
  0x3c, 0xb3, 0xea, 0xe6, 0x6c, 0x6b, 0x2c, 0x8f, 0xa3, 0x8f, 0x12, 0x0f,
  0x9b, 0x4a, 0xb6, 0x2e, 0x43, 0xfd, 0x1e, 0x00, 0xff, 0xca, 0xb6, 0x31,
  0x08, 0x2b, 0x1d, 0xbb, 0x21, 0xe0, 0xe9, 0x8a, 0x48, 0xf2, 0xbb, 0x59,
  0xc7, 0x72, 0x72, 0x29, 0x53, 0x07, 0xdf, 0xb8, 0x70, 0x51, 0x61, 0x3f,
  0x70, 0x03, 0x02, 0x50, 0x5f, 0x9e, 0xf4, 0xfd, 0x96, 0x7d, 0x0e, 0x21,
  0x83, 0x25, 0x1b, 0xf1, 0x0d, 0xae, 0xd7, 0x5e, 0x36, 0x60, 0xdd, 0xa2,
  0x1f, 0x27, 0xe9, 0x85, 0xb5, 0x2f, 0x6b, 0xf6, 0x86, 0x38, 0x66, 0x38,
  0x6a, 0x44, 0x4d, 0xaa, 0xde, 0xce, 0xbc, 0xe9, 0x17, 0x90, 0x95, 0x5d,
  0x02, 0x82, 0x01, 0x01, 0x00, 0xf2, 0x1b, 0x07, 0xa6, 0x16, 0xf7, 0x58,
  0x9c, 0xef, 0x27, 0x1e, 0xdb, 0x58, 0xf1, 0x72, 0x7a, 0x30, 0xf3, 0x4c,
  0x32, 0x5c, 0x13, 0x38, 0xb9, 0x42, 0xe3, 0x46, 0x41, 0x6b, 0xdb, 0x72,
  0x54, 0xc8, 0x92, 0x58, 0xdf, 0xaa, 0xaa, 0x06, 0xe3, 0x2e, 0xc1, 0xe8,
  0x86, 0x5f, 0x5c, 0x3b, 0x4f, 0x5b, 0xe2, 0xb1, 0x55, 0xb4, 0xd8, 0x6d,
  0xe8, 0x0c, 0x78, 0xf2, 0x85, 0xf7, 0xe1, 0x08, 0x59, 0x81, 0x12, 0xa0,
  0xf1, 0x91, 0x4a, 0x9a, 0x8c, 0xa2, 0xf7, 0x7c, 0xae, 0x14, 0xb0, 0xbc,
  0x2b, 0x5e, 0xf2, 0xde, 0x1d, 0x7f, 0xb6, 0x2c, 0xf9, 0x69, 0x72, 0x1c,
  0xa5, 0xd6, 0x42, 0xdc, 0x2a, 0xeb, 0x2f, 0x4c, 0x3b, 0xac, 0x3e, 0xc6,
  0x70, 0xcb, 0x3a, 0x65, 0x2c, 0xc3, 0x9f, 0x40, 0x61, 0xa0, 0x43, 0xc9,
  0xde, 0xe3, 0x6b, 0x7f, 0x3a, 0x45, 0xc0, 0xb5, 0xab, 0x3b, 0xb3, 0x36,
  0x2e, 0x61, 0xc3, 0x2b, 0xa6, 0x40, 0xbf, 0x00, 0xce, 0xf5, 0x86, 0xd6,
  0x1e, 0xab, 0xeb, 0xf4, 0x2a, 0x5e, 0x51, 0xe2, 0x68, 0x3d, 0x64, 0x33,
  0x9f, 0x02, 0x22, 0x53, 0xa3, 0x10, 0x4b, 0x23, 0x3a, 0x1f, 0x67, 0xb2,
  0xfd, 0x65, 0x75, 0x66, 0x0c, 0x43, 0x46, 0xce, 0xcd, 0xf6, 0x43, 0xc8,
  0xb1, 0x93, 0xc0, 0x02, 0x02, 0x95, 0xc6, 0xaa, 0x81, 0x44, 0xa5, 0x76,
  0x09, 0x2f, 0x25, 0xb9, 0xe2, 0xf0, 0x8b, 0xd2, 0xb3, 0x33, 0x59, 0x1b,
  0xd6, 0xe1, 0x55, 0x46, 0xd9, 0x5b, 0x67, 0x27, 0x9f, 0x6d, 0x84, 0x9d,
  0x7f, 0x72, 0xf5, 0x00, 0x4f, 0x37, 0xcb, 0x65, 0xfa, 0x91, 0x95, 0x5a,
  0x57, 0x00, 0x72, 0xe7, 0x0a, 0x58, 0x1b, 0x44, 0xdb, 0x41, 0x9c, 0x94,
  0x59, 0x56, 0x62, 0xf2, 0x94, 0x89, 0x1a, 0xc3, 0xf5, 0xf6, 0xf0, 0x71,
  0xde, 0x4d, 0x67, 0x73, 0x1f, 0x82, 0xb5, 0xa4, 0x3f, 0x02, 0x82, 0x01,
  0x00, 0x71, 0xed, 0xce, 0x44, 0x2a, 0xeb, 0x1c, 0xa9, 0x4c, 0x51, 0x59,
  0x60, 0xef, 0xd2, 0x18, 0xb3, 0xb3, 0x4b, 0xb3, 0xb9, 0xe8, 0x6e, 0xc1,
  0x4a, 0x2d, 0x2c, 0x25, 0x75, 0x88, 0x1b, 0xbb, 0x64, 0xa8, 0x50, 0x48,
  0x85, 0x4a, 0xca, 0xb4, 0x2f, 0xee, 0xaa, 0x11, 0x8f, 0x13, 0x04, 0x1b,
  0xe6, 0x47, 0x14, 0xaf, 0xbb, 0x23, 0x37, 0x35, 0x2d, 0x65, 0xb3, 0xab,
  0x93, 0x76, 0x99, 0x2c, 0x97, 0xa3, 0xa7, 0xc2, 0x4a, 0x0b, 0xa5, 0x4b,
  0x3c, 0x7a, 0xb8, 0xd1, 0x7f, 0xc7, 0x0c, 0x1c, 0xe5, 0x5d, 0x3e, 0x5b,
  0xec, 0xa1, 0x0c, 0x83, 0xf9, 0x4e, 0x48, 0x15, 0x23, 0xe6, 0xb9, 0x41,
  0x69, 0x07, 0x1d, 0xa2, 0x89, 0xe3, 0x16, 0x1f, 0x6a, 0x00, 0xd7, 0x53,
  0x63, 0xbd, 0xf9, 0x32, 0x32, 0x56, 0x24, 0x7c, 0x25, 0xb3, 0xb2, 0xcf,
  0x03, 0x30, 0xb6, 0xbe, 0xce, 0xd4, 0xb0, 0xf3, 0xb3, 0x19, 0x93, 0x73,
  0xc7, 0x54, 0xba, 0x47, 0xc4, 0x52, 0xed, 0x49, 0x58, 0x67, 0xf5, 0x19,
  0xd5, 0x2a, 0x37, 0x0d, 0x19, 0xf9, 0xd1, 0xbe, 0x84, 0x9d, 0x6b, 0x10,
  0x9e, 0xe0, 0x0d, 0xd3, 0xbc, 0x4c, 0x1d, 0x2a, 0xfd, 0x46, 0x33, 0x53,
  0x6b, 0x08, 0x62, 0x4a, 0x8e, 0xb9, 0xc6, 0x6e, 0xa0, 0xda, 0x3e, 0x2f,
  0x68, 0xd5, 0x68, 0x94, 0x80, 0x08, 0x67, 0x03, 0x58, 0x75, 0x94, 0xd3,
  0x2d, 0x75, 0x87, 0x2e, 0x93, 0x95, 0xe3, 0x0a, 0x93, 0x72, 0xed, 0x85,
  0xea, 0xbd, 0xeb, 0x25, 0x21, 0x5b, 0x7b, 0xe6, 0x61, 0x86, 0xf8, 0x00,
  0xb3, 0xbd, 0xcc, 0xff, 0xba, 0xf1, 0x88, 0x20, 0xd9, 0x65, 0xf3, 0x7c,
  0x2f, 0x1d, 0x36, 0xf7, 0x53, 0xbf, 0x57, 0xdf, 0x95, 0x36, 0x80, 0xb5,
  0x7a, 0xe1, 0xc9, 0x34, 0xb3, 0x83, 0xba, 0x95, 0xfc, 0x24, 0x0c, 0xe9,
  0xc1, 0x95, 0x71, 0xf3, 0x75, 0x02, 0x82, 0x01, 0x01, 0x00, 0xa8, 0x14,
  0xe1, 0xf3, 0x8a, 0x40, 0x40, 0xb1, 0xfb, 0x4a, 0xc2, 0x9e, 0x70, 0x1a,
  0x78, 0x6a, 0xa2, 0xaf, 0x56, 0xb8, 0x23, 0xba, 0x68, 0x88, 0x1e, 0x0a,
  0xe1, 0x8c, 0xab, 0xcf, 0xd7, 0x89, 0x4b, 0x12, 0x67, 0x47, 0x29, 0x1a,
  0x0f, 0xdc, 0x0b, 0x6b, 0x2d, 0xfe, 0x94, 0x17, 0xd9, 0x49, 0x58, 0x36,
  0x82, 0xfd, 0x48, 0xa7, 0x75, 0x6e, 0x43, 0xb2, 0x78, 0x55, 0x4f, 0xe9,
  0x58, 0x3d, 0xa3, 0x61, 0x86, 0x81, 0x0f, 0x68, 0xa6, 0xf1, 0x7a, 0x76,
  0xad, 0x85, 0xc1, 0xf1, 0x8d, 0x41, 0xe3, 0x12, 0x63, 0xe8, 0x40, 0xf0,
  0xfe, 0x3a, 0x4d, 0xdd, 0x9e, 0x4b, 0xf7, 0xfb, 0xc5, 0x14, 0xba, 0xe0,
  0xc4, 0x61, 0x2d, 0x4d, 0x0b, 0xc1, 0xe5, 0x25, 0xee, 0x75, 0xec, 0x7e,
  0x14, 0x59, 0x72, 0xc5, 0x7d, 0x52, 0x13, 0xbb, 0x5e, 0xc1, 0xdb, 0x09,
  0x56, 0x56, 0xc2, 0x04, 0xc2, 0x59, 0xe3, 0x1f, 0x77, 0x9f, 0x5d, 0x95,
  0xfd, 0x7e, 0xb1, 0x70, 0xe2, 0x18, 0xbb, 0x2c, 0xfd, 0xff, 0xa8, 0x29,
  0xdb, 0x30, 0x99, 0x66, 0x86, 0x7c, 0x1f, 0x24, 0x2b, 0xc2, 0xaa, 0x9e,
  0x2f, 0x9f, 0xbb, 0x8b, 0xe7, 0xf5, 0x0a, 0x4a, 0x3e, 0x05, 0xc7, 0x73,
  0x52, 0x42, 0x25, 0x75, 0x9b, 0xd0, 0xc5, 0x0d, 0xe9, 0x97, 0x57, 0xda,
  0x6c, 0x27, 0x80, 0xbc, 0x0a, 0xbd, 0x87, 0x90, 0xfe, 0x83, 0xb2, 0x92,
  0xb0, 0x3e, 0x1f, 0x28, 0xff, 0x2d, 0xe8, 0x94, 0xa6, 0xb2, 0x62, 0x45,
  0xb4, 0x79, 0x77, 0xb4, 0x39, 0x0f, 0xf1, 0x84, 0x6c, 0xa9, 0x92, 0xc7,
  0xd0, 0x4d, 0xec, 0x62, 0xaf, 0x2c, 0x75, 0xb0, 0x4f, 0xfc, 0x9b, 0x7c,
  0x9b, 0x0a, 0x49, 0x7b, 0xe6, 0x76, 0x3b, 0x86, 0x48, 0x79, 0x9c, 0xd2,
  0x0b, 0x38, 0x29, 0x2f, 0x77, 0x2e, 0x69, 0xb8, 0xa7, 0x71, 0x39, 0xf2,
  0xd7, 0x4b, 0x02, 0x82, 0x01, 0x00, 0x13, 0x5f, 0xca, 0x33, 0xf7, 0xd8,
  0x9c, 0x4d, 0x40, 0x04, 0x85, 0xf9, 0x6c, 0x49, 0xac, 0xd3, 0x19, 0x56,
  0xe3, 0x3f, 0x1a, 0xb7, 0x24, 0x1f, 0x15, 0xae, 0x38, 0x50, 0xc3, 0xd0,
  0xe4, 0xf3, 0xaf, 0x34, 0xfd, 0x01, 0xc0, 0xf5, 0x7e, 0x11, 0x17, 0xd4,
  0x3a, 0x10, 0x87, 0x78, 0xd8, 0xa3, 0x0b, 0x73, 0x9d, 0x64, 0xcb, 0xdb,
  0x72, 0x88, 0xcb, 0x91, 0x4f, 0xba, 0x01, 0xdb, 0x68, 0x1b, 0x10, 0xd9,
  0x09, 0xd9, 0x67, 0xe4, 0x4e, 0x6d, 0x8a, 0x57, 0xef, 0x13, 0x0d, 0x99,
  0xd5, 0xed, 0xbd, 0xf2, 0x02, 0x20, 0x34, 0x9a, 0xda, 0x0a, 0x9a, 0xc2,
  0x0b, 0x35, 0xa2, 0xfb, 0xb9, 0x2a, 0xc7, 0x2c, 0x5f, 0x67, 0xfe, 0xa7,
  0xe0, 0xf7, 0x11, 0x86, 0xeb, 0x41, 0x67, 0xbd, 0x4c, 0x7d, 0xfb, 0x85,
  0x3c, 0xdd, 0xd3, 0x2b, 0xf7, 0xcd, 0x12, 0x48, 0xca, 0x47, 0xf2, 0x9d,
  0x9f, 0xbd, 0x58, 0xca, 0x1c, 0x89, 0x26, 0xaa, 0xcc, 0x10, 0x9f, 0xfd,
  0x9d, 0x0a, 0x5c, 0x10, 0x4d, 0x78, 0x87, 0xf3, 0xb9, 0x20, 0x92, 0x6d,
  0xcd, 0x10, 0xc7, 0xf2, 0xc4, 0xaa, 0xcc, 0xd1, 0xc5, 0xc3, 0x1a, 0x28,
  0x33, 0xaa, 0x98, 0x5d, 0xc9, 0x5d, 0xee, 0x4b, 0x9b, 0xf2, 0xeb, 0x5f,
  0xcb, 0x85, 0xf0, 0x76, 0x73, 0x7d, 0xcc, 0x2d, 0x34, 0x85, 0xe0, 0x06,
  0xfa, 0xa9, 0x64, 0x86, 0x70, 0x17, 0xb2, 0xe6, 0xbf, 0x8c, 0x16, 0x87,
  0xdb, 0xfb, 0xf6, 0xe3, 0x13, 0x01, 0x4c, 0xd0, 0x64, 0x42, 0x4c, 0x69,
  0xf0, 0xc1, 0x43, 0xdf, 0x61, 0x83, 0xd1, 0xc7, 0x65, 0x9d, 0xb4, 0x7c,
  0x9e, 0x9a, 0x08, 0xcd, 0x02, 0xe4, 0x5f, 0x70, 0xca, 0xa9, 0x79, 0xcf,
  0x96, 0x3f, 0xad, 0x36, 0x06, 0xfb, 0x00, 0x7b, 0x6e, 0x3f, 0x99, 0x9b,
  0x76, 0x8c, 0x79, 0x24, 0x9b, 0xbb, 0xdb, 0x87, 0x7b, 0x2c
};
// const unsigned int iot_x509_private_key_len = sizeof(iot_x509_private_key);
const unsigned int iot_x509_private_key_len = 2374;

#endif