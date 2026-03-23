// BFLOAT16 VECTOR ADDITION
// Each thread processes 4 __nv_bfloat16 elements

__global__ void vecAdd_bf16(const __nv_bfloat16* A,
                            const __nv_bfloat16* B,
                            __nv_bfloat16* C,
                            int N)
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    int base = idx * 4;

    if (base + 3 < N) {
        C[base + 0] = __hadd(A[base + 0], B[base + 0]);
        C[base + 1] = __hadd(A[base + 1], B[base + 1]);
        C[base + 2] = __hadd(A[base + 2], B[base + 2]);
        C[base + 3] = __hadd(A[base + 3], B[base + 3]);
    }
}