%%writefile vecFMA_bf16.cu
#include <cuda_bf16.h>

///////////////////////////////////////////////////////////////
// BFLOAT16 VECTOR FMA (2 logical stages)
// Each thread processes 4 × __nv_bfloat16 elements
///////////////////////////////////////////////////////////////

__global__ void vecFMA_bf16(const __nv_bfloat16* A,
                            const __nv_bfloat16* B,
                            const __nv_bfloat16* C,
                            __nv_bfloat16* D,
                            int N)
{
    int idx  = blockIdx.x * blockDim.x + threadIdx.x;
    int base = idx * 4;

    if (base + 3 < N)
    {
        ///////////////////////////////////////////////////////////
        // Stage 1 : Load and Convert to FP32
        ///////////////////////////////////////////////////////////
        float a0 = __bfloat162float(A[base + 0]);
        float b0 = __bfloat162float(B[base + 0]);
        float c0 = __bfloat162float(C[base + 0]);

        float a1 = __bfloat162float(A[base + 1]);
        float b1 = __bfloat162float(B[base + 1]);
        float c1 = __bfloat162float(C[base + 1]);

        float a2 = __bfloat162float(A[base + 2]);
        float b2 = __bfloat162float(B[base + 2]);
        float c2 = __bfloat162float(C[base + 2]);

        float a3 = __bfloat162float(A[base + 3]);
        float b3 = __bfloat162float(B[base + 3]);
        float c3 = __bfloat162float(C[base + 3]);

        ///////////////////////////////////////////////////////////
        // Stage 2 : FMA + Convert back to BF16 + Store
        ///////////////////////////////////////////////////////////
        D[base + 0] = __float2bfloat16(a0 * b0 + c0);
        D[base + 1] = __float2bfloat16(a1 * b1 + c1);
        D[base + 2] = __float2bfloat16(a2 * b2 + c2);
        D[base + 3] = __float2bfloat16(a3 * b3 + c3);
    }
}