
// BFLOAT16 ReLU Activation
// Each thread processes 4 × __nv_bfloat16 elements

__global__ void relu_bf16(const __nv_bfloat16* input,
                          __nv_bfloat16* output,
                          int N)
{
    int idx  = blockIdx.x * blockDim.x + threadIdx.x;
    int base = idx * 4;

    if (base + 3 < N) {

        __nv_bfloat16 zero = __float2bfloat16(0.0f);

        __nv_bfloat16 x0 = input[base + 0];
        __nv_bfloat16 x1 = input[base + 1];
        __nv_bfloat16 x2 = input[base + 2];
        __nv_bfloat16 x3 = input[base + 3];

        output[base + 0] = __hgt(x0, zero) ? x0 : zero;
        output[base + 1] = __hgt(x1, zero) ? x1 : zero;
        output[base + 2] = __hgt(x2, zero) ? x2 : zero;
        output[base + 3] = __hgt(x3, zero) ? x3 : zero;
    }
}