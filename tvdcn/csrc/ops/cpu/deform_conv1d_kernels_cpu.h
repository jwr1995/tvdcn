#pragma once

#include <ATen/ATen.h>

namespace tvdcn {
    namespace ops {
        void arr2col_cpu(
                const at::Tensor &input,
                const at::Tensor &offset,
                const at::Tensor &mask,
                int in_channels,
                int width,
                int weight_w,
                int pad_w,
                int stride_w,
                int dilation_w,
                int out_w,
                int batch_sz,
                int offset_groups,
                int mask_groups,
                bool deformable,
                bool modulated,
                at::Tensor &columns);

        void col2arr_cpu(
                const at::Tensor &columns,
                const at::Tensor &offset,
                const at::Tensor &mask,
                int in_channels,
                int width,
                int weight_w,
                int pad_w,
                int stride_w,
                int dilation_w,
                int out_w,
                int batch_sz,
                int offset_groups,
                int mask_groups,
                bool deformable,
                bool modulated,
                at::Tensor &grad_input);

        void deform_conv1d_compute_grad_offset_cpu(
                const at::Tensor &columns,
                const at::Tensor &input,
                const at::Tensor &offset,
                const at::Tensor &mask,
                int in_channels,
                int width,
                int weight_w,
                int pad_w,
                int stride_w,
                int dilation_w,
                int out_w,
                int batch_sz,
                int offset_groups,
                int mask_groups,
                bool deformable,
                bool modulated,
                at::Tensor &grad_offset);

        void deform_conv1d_compute_grad_mask_cpu(
                const at::Tensor &columns,
                const at::Tensor &input,
                const at::Tensor &offset,
                int in_channels,
                int width,
                int weight_w,
                int pad_w,
                int stride_w,
                int dilation_w,
                int out_w,
                int batch_sz,
                int offset_groups,
                int mask_groups,
                bool deformable,
                bool modulated,
                at::Tensor &grad_mask);
    }
}
