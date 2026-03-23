%%writefile relu_bf16.cu
#include <cuda_bf16.h>

///////////////////////////////////////////////////////////////
// BFLOAT16 ReLU Activation (2 logical stages)
// Each thread processes 4 × __nv_bfloat16 elements
///////////////////////////////////////////////////////////////

__global__ void relu_bf16(const __nv_bfloat16* input,
                          __nv_bfloat16* output,
                          int N)
{
    int idx  = blockIdx.x * blockDim.x + threadIdx.x;
    int base = idx * 4;

    if (base + 3 < N)
    {
        ///////////////////////////////////////////////////////////
        // Stage 1 : Load and Convert to FP32
        ///////////////////////////////////////////////////////////
        float x0 = __bfloat162float(input[base + 0]);
        float x1 = __bfloat162float(input[base + 1]);
        float x2 = __bfloat162float(input[base + 2]);
        float x3 = __bfloat162float(input[base + 3]);

        ///////////////////////////////////////////////////////////
        // Stage 2 : ReLU + Convert back to BF16 + Store
        ///////////////////////////////////////////////////////////
        x0 = (x0 > 0.0f) ? x0 : 0.0f;
        x1 = (x1 > 0.0f) ? x1 : 0.0f;
        x2 = (x2 > 0.0f) ? x2 : 0.0f;
        x3 = (x3 > 0.0f) ? x3 : 0.0f;

        output[base + 0] = __float2bfloat16(x0);
        output[base + 1] = __float2bfloat16(x1);
        output[base + 2] = __float2bfloat16(x2);
        output[base + 3] = __float2bfloat16(x3);
    }
}