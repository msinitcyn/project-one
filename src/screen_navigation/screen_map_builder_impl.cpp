#include "screen_navigation/screen_map_builder_impl.h"

using std::string;

namespace ProjectOne::ScreenNavigation {
    ScreenSector ScreenMapBuilderImpl::build(float x, float y, float width, float height) {
        ScreenSector result(nullptr, x, y, width, height);
        const vector<string> rows = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
        const int numRows = rows.size();
        const float widthStep = 1.0f / 10.0f;
        const float heightStep = 1.0f / 3.0f;

        for (int row = 0; row < numRows; ++row) {
            float startY = row * heightStep;
            for (int col = 0; col < (int)rows[row].length(); ++col) {
                float startX = col * widthStep;
                ScreenSector* sector = new ScreenSector(&result, startX, startY, widthStep, heightStep);
                result.inner_sectors[string(1, rows[row][col])] = sector;
            }
        }

        return result;
    }
}
