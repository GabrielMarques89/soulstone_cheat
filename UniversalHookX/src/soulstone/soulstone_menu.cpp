#include "../dependencies/imgui/imgui_impl_win32.h"
#include <Windows.h>
#include "soulstone.h"

namespace soulstone_menu {
    bool active = false;

    void unlimited_runes_button( ) {
        ImGui::Text("Add 10 skill points:");

        if (ImGui::Button("10 skill points")) {
            CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)soulstone::add_skills, nullptr, NULL, NULL);
        }
        // static bool* unlimited_runes_active = new bool(false);

        // if (ImGui::Button(*unlimited_runes_active ? "Desativar" : "Ativar")) {
        //     *unlimited_runes_active = !*unlimited_runes_active;
        //     if (*unlimited_runes_active) {
        //         CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)soulstone::add_skills, nullptr, NULL, NULL);
        //     }
        // }
    }
}
