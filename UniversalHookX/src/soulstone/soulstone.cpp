#include "soulstone.h"

#include <Windows.h>
#include <vector>
#include <tchar.h>

namespace soulstone {
    DWORD_PTR* get_pointer(uintptr_t base, std::vector<uintptr_t> offsets) {
        DWORD_PTR* result = nullptr;
        for (auto offset : offsets) {
            if (result == nullptr) {
                result = reinterpret_cast<DWORD_PTR*>(base + offset);
            } else {
                result = reinterpret_cast<DWORD_PTR*>(*result + offset);
            }
        }
        return result;
    }


    DWORD_PTR* sumPointers(uintptr_t a, uintptr_t b) {
        return reinterpret_cast<DWORD_PTR*>(a + b);
    }

    // DWORD_PTR* skills_pointer = get_pointer(reinterpret_cast<uintptr_t>(GetModuleHandleA("UnityPlayer.dll")),
    //                                         {0x019DD5C8, 0x128, 0x90, 0x10, 0x60, 0x68, 0x4C});

    std::vector<uintptr_t> offsets = {0x19DD5C8, 0x118, 0x0, 0x30, 0x38, 0x28, 0xC8, 0x18};
    DWORD_PTR* skill_ptr = get_pointer(reinterpret_cast<uintptr_t>(GetModuleHandleA("UnityPlayer.dll")), offsets);
    constexpr long refresh_delay = 500;
    bool isActive = true;

    void unlimited_runes( ) {
        while (true) {
            if (!isActive) {
                return;
            }

            try {
                // *skills_pointer = 0;
            } catch (...) {
                // do nothing - values not loaded yet
            }

            // isActive = false;
            Sleep(refresh_delay);
        }
    }

    void unlimited_hp(bool* active) {
        while (*active) {
            try {
                *skill_ptr = *skill_ptr + 10;
            } catch (...) {
                // do nothing - values not loaded yet
            }
            Sleep(refresh_delay);
        }
    }

    void add_skills( ) {
        try {
            *skill_ptr = *skill_ptr + 10;
        } catch (...) {
            // do nothing - values not loaded yet
        }
    }

}
