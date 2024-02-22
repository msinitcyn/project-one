namespace ProjectOne::Screen {
    class OverlayScreen {
    public:
        virtual void draw() = 0;
        virtual void hide() = 0;

        ~OverlayScreen() {
        }
    };
}
