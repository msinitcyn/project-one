#include "screen_navigation/screen_map_builder_impl.h"

namespace ProjectOne::ScreenNavigation {
    ScreenSector ScreenMapBuilderImpl::build() {
        ScreenSector result("", 0, 0, 1, 1);
        const std::string rows[] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
        const int numRows = sizeof(rows) / sizeof(rows[0]);
        const float widthStep = 1.0f / 10.0f;
        const float heightStep = 1.0f / 3.0f;

        for (int row = 0; row < numRows; ++row) {
            float startY = row * heightStep;
            for (int col = 0; col < rows[row].size(); ++col) {
                float startX = col * widthStep;
                ScreenSector sector(std::string(1, rows[row][col]), startX, startY, widthStep, heightStep);
                result.inner_sectors.push_back(sector);
            }
        }

        return result;
    }
}
