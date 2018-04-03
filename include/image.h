
/*!
 ************************************************************************
 * \file image.h
 *
 * \brief
 *    prototypes for image.c
 *
 ************************************************************************
 */

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "mbuffer.h"
//#define EXTRACT_PERCENT 0.01
#define MAX_KEY_DATA_LEN 8
//extern int g_KeyUnitIdx;


extern void calculate_frame_no(VideoParameters *p_Vid, StorablePicture *p);

extern void decode_one_slice  (Slice *currSlice);
extern int  read_new_slice    (Slice *currSlice,AVPacket *packet);
extern void exit_picture      (VideoParameters *p_Vid, StorablePicture **dec_picture);
extern int  decode_one_frame  (DecoderParams *pDecoder,AVPacket *packet);

extern int  is_new_picture(StorablePicture *dec_picture, Slice *currSlice, OldSliceParams *p_old_slice);
extern void init_old_slice(OldSliceParams *p_old_slice);
// For 4:4:4 independent mode
extern void copy_dec_picture_JV (VideoParameters *p_Vid, StorablePicture *dst, StorablePicture *src );

extern void frame_postprocessing(VideoParameters *p_Vid);
extern void field_postprocessing(VideoParameters *p_Vid);

#if (MVC_EXTENSION_ENABLE)
extern int GetViewIdx(VideoParameters *p_Vid, int iVOIdx);
extern int GetVOIdx(VideoParameters *p_Vid, int iViewId);
extern int get_maxViewIdx(VideoParameters *p_Vid, int view_id, int anchor_pic_flag, int listidx);
#endif

extern void init_slice(VideoParameters *p_Vid, Slice *currSlice);
extern void decode_slice(Slice *currSlice, int current_header);

#endif
