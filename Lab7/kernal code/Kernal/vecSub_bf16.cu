%%writefile vecSub_bf16.cu
#include <cuda_bf16.h>

///////////////////////////////////////////////////////////////
// BFLOAT16 VECTOR SUBTRACTION
// Each thread processes 4 __nv_bfloat16 elements
///////////////////////////////////////////////////////////////

__global__ void vecSub_bf16(const __nv_bfloat16* A,
                            const __nv_bfloat16* B,
                            __nv_bfloat16* C,
                            int N)
{
    int idx  = blockIdx.x * blockDim.x + threadIdx.x;
    int base = idx * 4;

    if (base + 3 < N) {

        float a0 = __bfloat162float(A[base + 0]);
        float b0 = __bfloat162float(B[base + 0]);

        float a1 = __bfloat162float(A[base + 1]);
        float b1 = __bfloat162float(B[base + 1]);

        float a2 = __bfloat162float(A[base + 2]);
        float b2 = __bfloat162float(B[base + 2]);

        float a3 = __bfloat162float(A[base + 3]);
        float b3 = __bfloat162float(B[base + 3]);

        C[base + 0] = __float2bfloat16(a0 - b0);
        C[base + 1] = __float2bfloat16(a1 - b1);
        C[base + 2] = __float2bfloat16(a2 - b2);
        C[base + 3] = __float2bfloat16(a3 - b3);
    }
}