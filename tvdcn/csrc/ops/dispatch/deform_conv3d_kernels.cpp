#include "../cpu/deform_conv3d_kernels_cpu.h"

#ifdef WITH_CUDA

#include "../cuda/deform_conv3d_kernels_cuda.h"

#endif

namespace tvdcn {
    namespace ops {
        void vol2col(
                const at::Tensor &input,
                const at::Tensor &offset,
                const at::Tensor &mask,
                const int in_channels,
                const int depth,
                const int height,
                const int width,
                const int weight_d,
                const int weight_h,
                const int weight_w,
                const int pad_d,
                const int pad_h,
                const int pad_w,
                const int stride_d,
                const int stride_h,
                const int stride_w,
                const int dilation_d,
                const int dilation_h,
                const int dilation_w,
                const int out_d,
                const int out_h,
                const int out_w,
                const int batch_sz,
                const int offset_groups,
                const int mask_groups,
                const bool deformable,
                const bool modulated,
                at::Tensor &columns) {
            if (input.device().is_cuda()) {
#if defined(WITH_CUDA) || defined(WITH_HIP)
                vol2col_cuda(input,
                             offset,
                             mask,
                             in_channels,
                             depth,
                             height,
                             width,
                             weight_d,
                             weight_h,
                             weight_w,
                             pad_d,
                             pad_h,
                             pad_w,
                             stride_d,
                             stride_h,
                             stride_w,
                             dilation_d,
                             dilation_h,
                             dilation_w,
                             out_d,
                             out_h,
                             out_w,
                             batch_sz,
                             offset_groups,
                             mask_groups,
                             deformable,
                             modulated,
                             columns);
#else
                AT_ERROR("Not compiled with GPU support");
#endif
            } else {
                vol2col_cpu(input,
                            offset,
                            mask,
                            in_channels,
                            depth,
                            height,
                            width,
                            weight_d,
                            weight_h,
                            weight_w,
                            pad_d,
                            pad_h,
                            pad_w,
                            stride_d,
                            stride_h,
                            stride_w,
                            dilation_d,
                            dilation_h,
                            dilation_w,
                            out_d,
                            out_h,
                            out_w,
                            batch_sz,
                            offset_groups,
                            mask_groups,
                            deformable,
                            modulated,
                            columns);
            }
        }

        void col2vol(
                const at::Tensor &columns,
                const at::Tensor &offset,
                const at::Tensor &mask,
                const int in_channels,
                const int depth,
                const int height,
                const int width,
                const int weight_d,
                const int weight_h,
                const int weight_w,
                const int pad_d,
                const int pad_h,
                const int pad_w,
                const int stride_d,
                const int stride_h,
                const int stride_w,
                const int dilation_d,
                const int dilation_h,
                const int dilation_w,
                const int out_d,
                const int out_h,
                const int out_w,
                const int batch_sz,
                const int offset_groups,
                const int mask_groups,
                const bool deformable,
                const bool modulated,
                at::Tensor &grad_input) {
            if (grad_input.device().is_cuda()) {
#if defined(WITH_CUDA) || defined(WITH_HIP)
                col2vol_cuda(columns,
                             offset,
                             mask,
                             in_channels,
                             depth,
                             height,
                             width,
                             weight_d,
                             weight_h,
                             weight_w,
                             pad_d,
                             pad_h,
                             pad_w,
                             stride_d,
                             stride_h,
                             stride_w,
                             dilation_d,
                             dilation_h,
                             dilation_w,
                             out_d,
                             out_h,
                             out_w,
                             batch_sz,
                             offset_groups,
                             mask_groups,
                             deformable,
                             modulated,
                             grad_input);
#else
                AT_ERROR("Not compiled with GPU support");
#endif
            } else {
                col2vol_cpu(columns,
                            offset,
                            mask,
                            in_channels,
                            depth,
                            height,
                            width,
                            weight_d,
                            weight_h,
                            weight_w,
                            pad_d,
                            pad_h,
                            pad_w,
                            stride_d,
                            stride_h,
                            stride_w,
                            dilation_d,
                            dilation_h,
                            dilation_w,
                            out_d,
                            out_h,
                            out_w,
                            batch_sz,
                            offset_groups,
                            mask_groups,
                            deformable,
                            modulated,
                            grad_input);
            }
        }

        void deform_conv3d_compute_grad_offset(
                const at::Tensor &columns,
                const at::Tensor &input,
                const at::Tensor &offset,
                const at::Tensor &mask,
                const int in_channels,
                const int depth,
                const int height,
                const int width,
                const int weight_d,
                const int weight_h,
                const int weight_w,
                const int pad_d,
                const int pad_h,
                const int pad_w,
                const int stride_d,
                const int stride_h,
                const int stride_w,
                const int dilation_d,
                const int dilation_h,
                const int dilation_w,
                const int out_d,
                const int out_h,
                const int out_w,
                const int batch_sz,
                const int offset_groups,
                const int mask_groups,
                const bool deformable,
                const bool modulated,
                at::Tensor &grad_offset) {
            if (input.device().is_cuda()) {
#if defined(WITH_CUDA) || defined(WITH_HIP)
                deform_conv3d_compute_grad_offset_cuda(columns,
                                                       input,
                                                       offset,
                                                       mask,
                                                       in_channels,
                                                       depth,
                                                       height,
                                                       width,
                                                       weight_d,
                                                       weight_h,
                                                       weight_w,
                                                       pad_d,
                                                       pad_h,
                                                       pad_w,
                                                       stride_d,
                                                       stride_h,
                                                       stride_w,
                                                       dilation_d,
                                                       dilation_h,
                                                       dilation_w,
                                                       out_d,
                                                       out_h,
                                                       out_w,
                                                       batch_sz,
                                                       offset_groups,
                                                       mask_groups,
                                                       deformable,
                                                       modulated,
                                                       grad_offset);
#else
                AT_ERROR("Not compiled with GPU support");
#endif
            } else {
                deform_conv3d_compute_grad_offset_cpu(columns,
                                                      input,
                                                      offset,
                                                      mask,
                                                      in_channels,
                                                      depth,
                                                      height,
                                                      width,
                                                      weight_d,
                                                      weight_h,
                                                      weight_w,
                                                      pad_d,
                                                      pad_h,
                                                      pad_w,
                                                      stride_d,
                                                      stride_h,
                                                      stride_w,
                                                      dilation_d,
                                                      dilation_h,
                                                      dilation_w,
                                                      out_d,
                                                      out_h,
                                                      out_w,
                                                      batch_sz,
                                                      offset_groups,
                                                      mask_groups,
                                                      deformable,
                                                      modulated,
                                                      grad_offset);
            }
        }

        void deform_conv3d_compute_grad_mask(
                const at::Tensor &columns,
                const at::Tensor &input,
                const at::Tensor &offset,
                const int in_channels,
                const int depth,
                const int height,
                const int width,
                const int weight_d,
                const int weight_h,
                const int weight_w,
                const int pad_d,
                const int pad_h,
                const int pad_w,
                const int stride_d,
                const int stride_h,
                const int stride_w,
                const int dilation_d,
                const int dilation_h,
                const int dilation_w,
                const int out_d,
                const int out_h,
                const int out_w,
                const int batch_sz,
                const int offset_groups,
                const int mask_groups,
                const bool deformable,
                const bool modulated,
                at::Tensor &grad_mask) {
            if (input.device().is_cuda()) {
#if defined(WITH_CUDA) || defined(WITH_HIP)
                deform_conv3d_compute_grad_mask_cuda(columns,
                                                     input,
                                                     offset,
                                                     in_channels,
                                                     depth,
                                                     height,
                                                     width,
                                                     weight_d,
                                                     weight_h,
                                                     weight_w,
                                                     pad_d,
                                                     pad_h,
                                                     pad_w,
                                                     stride_d,
                                                     stride_h,
                                                     stride_w,
                                                     dilation_d,
                                                     dilation_h,
                                                     dilation_w,
                                                     out_d,
                                                     out_h,
                                                     out_w,
                                                     batch_sz,
                                                     offset_groups,
                                                     mask_groups,
                                                     deformable,
                                                     modulated,
                                                     grad_mask);
#else
                AT_ERROR("Not compiled with GPU support");
#endif
            } else {
                deform_conv3d_compute_grad_mask_cpu(columns,
                                                    input,
                                                    offset,
                                                    in_channels,
                                                    depth,
                                                    height,
                                                    width,
                                                    weight_d,
                                                    weight_h,
                                                    weight_w,
                                                    pad_d,
                                                    pad_h,
                                                    pad_w,
                                                    stride_d,
                                                    stride_h,
                                                    stride_w,
                                                    dilation_d,
                                                    dilation_h,
                                                    dilation_w,
                                                    out_d,
                                                    out_h,
                                                    out_w,
                                                    batch_sz,
                                                    offset_groups,
                                                    mask_groups,
                                                    deformable,
                                                    modulated,
                                                    grad_mask);
            }
        }
    }
}
