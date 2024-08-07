#include "screen_navigation/screen_map_builder.h"

using std::string;

namespace ProjectOne::ScreenNavigation {
    vector<ScreenSector*> ScreenMapBuilder::build(int x, int y, int width, int height) {
        vector<string> content = {"1234567890", "qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
        if (width < 20) {
            content = {"ru","fh"};
        }
        const int rows = content.size();
        const int cols = content[0].size();
        const int width_step = width/cols;
        const int height_step = height/rows;

        vector<ScreenSector*> result(rows*cols);

        for (int row = 0; row < rows; ++row) {
            const int cols = content[0].size();
            int start_y = row * height_step;
            for (int col = 0; col < cols; ++col) {
                int start_x = col * width_step;
                ScreenSector* sector = new ScreenSector(string(1,content[row][col]), x+start_x, y+start_y, width_step, height_step);
                result[row*cols+col] = sector;
            }
        }

        return result;
    }
}
