import torch

from tvdcn import *


def test_wrapper():
    conv = DeformConvTranspose2d(4, 2, kernel_size=(2, 2))
    conv = torch.jit.script(conv)
    print(conv)


def test_packed_wrapper():
    x = torch.randn(1, 4, 4, 5, requires_grad=True)

    conv = PackedDeformConvTranspose2d(4, 2,
                                       kernel_size=(2, 3),
                                       stride=(2, 3),
                                       padding=(2, 3),
                                       groups=2,
                                       modulated=True)
    conv = torch.jit.script(conv)
    print(conv)

    out = conv(x)
    print('input_shape: ', x.shape)
    print('output_shape:', out.shape)

    out.sum().backward()
    assert x.grad is not None


if __name__ == '__main__':
    test_wrapper()
    test_packed_wrapper()
