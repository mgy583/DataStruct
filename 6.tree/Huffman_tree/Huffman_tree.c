#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// 定义节点结构体
typedef struct HuffmanNode {
    unsigned char ch;
    int freq;
    struct HuffmanNode *left, *right;
}HuffmanNode;


// 最小堆 
typedef struct {
    HuffmanNode **data;
    int size, capacity;
}MidHeap;

static void swap_nodes(HuffmanNode **a, HuffmanNode **b) {
    HuffmanNode *t = *a;
    *a = *b;
    *b = t;
}

static void heapify_down(MidHeap *h, int i) {
    int l = 2*i + 1, r = 2*i + 2, smallest = i;
    if (l < h->size && h->data[l]->freq < h->data[smallest]->freq)
        smallest = l;
    if (r < h->size && h->data[r]->freq < h->data[smallest]->freq)
        smallest = r;
    if (smallest != i) {
        swap_nodes(&h->data[i], &h->data[smallest]);
        heapify_down(h, smallest);
    }    
}

static void heap_push(MidHeap *h, HuffmanNode *node) {
    if (h->size == h->capacity) {
        h->capacity <<= 1;
        h->data = realloc(h->data, h->capacity * sizeof(HuffmanNode *));
    }
    int i = h->size++;
    h->data[i] = node;
    while (i && h->data[(i-1)/2]->freq > h->data[i]->freq) {
        swap_nodes(&h->data[i], &h->data[(i-1)/2]);
        i = (i-1)/2;
    }
}

static HuffmanNode* heap_pop(MidHeap *h) {
    if (h->size == 0) return NULL;
    HuffmanNode *min_node = h->data[0];
    h->data[0] = h->data[--h->size];
    heapify_down(h, 0);
    return min_node;
}


// 创建Huffman树
HuffmanNode* create_huffman_tree(int frequencies[256]) {
    MidHeap h;
    h.size = 0;
    h.capacity = 256;
    h.data = malloc(h.capacity * sizeof(HuffmanNode *));

    for (int i = 0; i < 256; i++)
        if (frequencies[i])
            heap_push(&h, &(HuffmanNode){.ch = (unsigned char)i, .freq = frequencies[i]});
    while (h.size > 1)
    {
        HuffmanNode *l = heap_pop(&h);
        HuffmanNode *r = heap_pop(&h);
        HuffmanNode *merged = malloc(sizeof(HuffmanNode));
        *merged = (HuffmanNode){.freq = l->freq + r->freq, .left = l, .right = r};
        heap_push(&h, merged);
    }
    HuffmanNode *root = h.size ? heap_pop(&h) : NULL;
    free(h.data);
    return root;
}

char code_tab[256][32];   // 每行放一串 '0'/'1' 字符串
int  code_len[256] = {0}; // 对应长度，方便快速拷贝

static void gen_codes(HuffmanNode *root, char *buf, int depth) {
    if (!root) return;
    if (!root->left && !root->right) { // 叶子
        buf[depth] = '\0';
        strcpy(code_tab[root->ch], buf);
        code_len[root->ch] = depth;
        return;
    }
    buf[depth] = '0'; gen_codes(root->left,  buf, depth+1);
    buf[depth] = '1'; gen_codes(root->right, buf, depth+1);
}

// 编码&解码
char *encode(const unsigned char *src, int slen, int *out_bits) {
    int total_bits = 0;
    for (int i = 0; i < slen; ++i) total_bits += code_len[src[i]];

    int byte_len = (total_bits + 7) / 8;
    char *out = calloc(1, byte_len + 1); // +1 方便当字符串打印
    int bit_idx = 0;
    for (int i = 0; i < slen; ++i) {
        const char *c = code_tab[src[i]];
        for (int k = 0; c[k]; ++k) {
            if (c[k] == '1')
                out[bit_idx >> 3] |= 1u << (7 - (bit_idx & 7));
            ++bit_idx;
        }
    }
    *out_bits = total_bits;
    return out;
}

unsigned char *decode(const char *bits, int total_bits, HuffmanNode *root, int *olen) {
    unsigned char *out = malloc(total_bits); // 最坏情况每 bit 一字符
    int cnt = 0;
    HuffmanNode *cur = root;
    for (int i = 0; i < total_bits; ++i) {
        int byte_i = i >> 3, bit_i = 7 - (i & 7);
        int bit = (bits[byte_i] >> bit_i) & 1;
        cur = bit ? cur->right : cur->left;
        if (!cur->left && !cur->right) {
            out[cnt++] = cur->ch;
            cur = root;
        }
    }
    *olen = cnt;
    return out;
}

// 释放Huffman树
void free_huffman_tree(HuffmanNode *root) {
    if (root) {
        free_huffman_tree(root->left);
        free_huffman_tree(root->right);
        free(root);
    }
}

int main() {
    const char *txt = "this is an example for huffman encoding";
    int freq[256] = {0};
    
    int n = strlen(txt);

    // 统计频率
    for (const char *p = txt; *p; ++p)
        freq[(unsigned char)*p]++;
    
    // 创建Huffman树
    HuffmanNode *root = create_huffman_tree(freq);
    
    char buf[32];
    gen_codes(root, buf, 0);

    // 编码
    int out_bits;
    char *encoded = encode((const unsigned char *)txt, n, &out_bits);
    printf("Encoded bits: ");
    for (int i = 0; i < (out_bits + 7) / 8; ++i)
        printf("%02X ", (unsigned char)encoded[i]);
    printf("\nTotal bits: %d\n", out_bits);
    // 解码
    int decoded_len;
    unsigned char *decoded = decode(encoded, out_bits, root, &decoded_len);
    printf("Decoded text: %.*s\n", decoded_len, decoded);
    // 清理
    free(encoded);
    free(decoded);
    free_huffman_tree(root);

    // 压缩率
    printf("Original size: %d bytes\n", n);
    printf("Compressed size: %d bytes\n", (out_bits + 7) / 8);  

    return 0;
}