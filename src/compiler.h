#ifndef __COMPILER_H
#define __COMPILER_H
// Low level definitions for C languange and gcc compiler.

#define barrier() __asm__ __volatile__("": : :"memory")

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

#define noinline __attribute__((noinline))
#ifndef __always_inline
#define __always_inline inline __attribute__((always_inline))
#endif
#define __visible __attribute__((externally_visible))
#define __noreturn __attribute__((noreturn))

#define PACKED __attribute__((packed))
#define __aligned(x) __attribute__((aligned(x)))
#define __section(S) __attribute__((section(S)))

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define ALIGN(x,a)              __ALIGN_MASK(x,(typeof(x))(a)-1)
#define __ALIGN_MASK(x,mask)    (((x)+(mask))&~(mask))
#define ALIGN_DOWN(x,a)         ((x) & ~((typeof(x))(a)-1))

#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})

#define __stringify_1(x)        #x
#define __stringify(x)          __stringify_1(x)

#define ___PASTE(a,b) a##b
#define __PASTE(a,b) ___PASTE(a,b)

#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define DIV_ROUND_CLOSEST(x, divisor)({                 \
            typeof(divisor) __divisor = divisor;        \
            (((x) + ((__divisor) / 2)) / (__divisor));  \
        })

static inline void writel(void *addr, uint32_t val) {
    *(volatile uint32_t *)addr = val;
}
static inline void writew(void *addr, uint16_t val) {
    *(volatile uint16_t *)addr = val;
}
static inline void writeb(void *addr, uint8_t val) {
    *(volatile uint8_t *)addr = val;
}
static inline uint32_t readl(const void *addr) {
    return *(volatile const uint32_t *)addr;
}
static inline uint16_t readw(const void *addr) {
    return *(volatile const uint16_t *)addr;
}
static inline uint8_t readb(const void *addr) {
    return *(volatile const uint8_t *)addr;
}

#endif // compiler.h
