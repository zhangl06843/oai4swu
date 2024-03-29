/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*!\file PHY/CODING/nrSmallBlock/nr_small_block_defs.h
 * \brief
 * \author Turker Yilmaz
 * \date 2019
 * \version 0.1
 * \company EURECOM
 * \email turker.yilmaz@eurecom.fr
 * \note
 * \warning
*/

#ifndef __NR_SMALL_BLOCK_DEFS__H__
#define __NR_SMALL_BLOCK_DEFS__H__

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define NR_SMALL_BLOCK_CODED_BITS 32

#define L1d_CLS 64

uint32_t encodeSmallBlock(int in, int len);

uint16_t decodeSmallBlock(int8_t *in, uint8_t len);

static const uint32_t nrSmallBlockBasis[11] = {0xFFFFFFFF, 0x4BA5A933, 0x7D910E5A, 0x6D26339C, 0x71C7C3E0,
		0x7E0FFC00, 0x731D8E64, 0x6B44F5B0, 0x7DC218EC, 0x4DA1B746, 0x42F0FFFF};

static const uint16_t properOrderedBasis[32] = {0x0000, 0x0002, 0x0004, 0x0006, 0x0008, 0x000A, 0x000C, 0x000E, 0x0010, 0x0012,
		0x0014, 0x0016, 0x0018, 0x001A, 0x001C, 0x001E, 0x0020, 0x0022, 0x0024, 0x0026,
		0x0028, 0x002A, 0x002C, 0x002E, 0x0030, 0x0032, 0x0034, 0x0036, 0x0038, 0x003A, 0x003C, 0x003E};

static const uint16_t properOrderedBasisExtended[32] = {0x0000, 0x0040, 0x0080, 0x00C0, 0x0100, 0x0140, 0x0180, 0x01C0, 0x0200, 0x0240,
		0x0280, 0x02C0, 0x0300, 0x0340, 0x0380, 0x03C0, 0x0400, 0x0440, 0x0480, 0x04C0,
		0x0500, 0x0540, 0x0580, 0x05C0, 0x0600, 0x0640, 0x0680, 0x06C0, 0x0700, 0x0740, 0x0780, 0x07C0};

static const int8_t hadamard32InterleavedTransposed[32][32] __attribute__ ((aligned(32))) = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{-1,-1,1,1,-1,-1,1,1,-1,1,1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,1,-1,1},
		{1,-1,1,-1,-1,1,-1,1,1,-1,-1,-1,1,1,1,1,-1,1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,1},
		{-1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,1},
		{1,1,-1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,1},
		{-1,-1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,1,1,1,1,1,-1,1,-1,-1,1,1,-1,1,1},
		{1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,-1,1,-1,1,1,1,1,-1,1,1,1},
		{-1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,1},
		{1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1},
		{-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,1},
		{1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,1,1,1,-1,-1,1,1,1,1},
		{-1,1,1,-1,1,1,1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1},
		{1,1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,1,1,1},
		{-1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,1,-1,1,1,1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,1},
		{1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,1},
		{-1,1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,1},
		{1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,1},
		{-1,-1,1,1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,1},
		{1,-1,1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,1,1,1},
		{-1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,1,-1,1},
		{1,1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,-1,1,1,-1,1,1,1},
		{-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,1,1,1,-1,1,1,1,-1,-1,1,-1,1},
		{1,-1,-1,1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1},
		{-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,1,1,-1,1,1},
		{1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,1},
		{-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,1,1,1,-1,1},
		{1,-1,1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,1},
		{-1,1,1,-1,1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,1},
		{1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,-1,1},
		{-1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,1,-1,1,-1,1,1},
		{1,-1,-1,1,1,-1,1,1,1,-1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,1,1},
		{-1,1,-1,1,-1,1,1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,-1,1}
};

static const int8_t maskD[32][32] __attribute__ ((aligned(32))) = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,1},
		{1,1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,1},
		{1,1,-1,1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,1,1,1,1,-1,-1,1,1,1},
		{1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,1},
		{1,1,1,-1,1,1,1,-1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,1,1},
		{1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,1,-1,-1,1,-1,1,1,1},
		{1,1,1,-1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,1,1,-1,-1,1},
		{1,-1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1},
		{1,-1,1,1,1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1},
		{1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,1,1},
		{1,-1,1,1,-1,1,1,-1,1,1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,1,-1,1},
		{1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,1},
		{1,-1,-1,-1,1,1,-1,-1,-1,1,1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,1},
		{1,-1,1,-1,-1,1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,1,-1,1},
		{1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,-1,1,1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,1},
		{-1,-1,1,-1,-1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,1},
		{-1,-1,-1,-1,1,1,-1,1,1,-1,1,-1,1,1,1,1,1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1},
		{-1,-1,1,-1,1,-1,1,1,1,1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,1},
		{-1,-1,1,1,-1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,1},
		{-1,-1,-1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,1,1,-1,1},
		{-1,-1,1,1,1,-1,1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,1},
		{-1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,1},
		{-1,1,1,-1,-1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,1},
		{-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,1},
		{-1,1,1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,1,1,1,1,1,-1,1,1,-1,-1,1},
		{-1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,1,-1,1,1,1,1,-1,-1,-1,1,-1,1,1,1},
		{-1,1,-1,1,-1,1,-1,1,1,1,1,1,-1,1,-1,1,-1,-1,1,1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,1},
		{-1,1,1,1,-1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,1,1},
		{-1,1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,1,1,1,},
		{-1,1,1,1,1,1,1,-1,-1,-1,1,-1,1,-1,1,1,1,-1,1,-1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,1}
};



#endif

