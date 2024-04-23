#ifndef EXTERNAL_MEMORY_IF
#define EXTERNAL_MEMORY_IF

namespace utils
{
    template <typename ExternalMemoryT, typename addr_t, typename reg_t, typename access_addr_t>
    struct ExternalMemoryIf
    {
        static void init()
        {
            ExternalMemoryT::init_impl();
        }
    };
}

#endif
