/*#include "Renderers/Window.h"
#include "Managers/TextureManager.h"
#include "Managers/FontManager.h"
#include "Renderers/Sprite.h"
#include "Renderers/ElasticSprite.h"
#include "Renderers/Text.h"
#include "Widgets/Label.h"
#include "Widgets/Button.h"
#include "Entities/Handler.h"

Window window("Hello", 800, 600, false);
TextureManager* txrMan = TextureManager::instance();
FontManager* fontMan = FontManager::instance();
Handler handler;

void init();
void loop();

int main()
{

    init();
    loop();

    return 0;
}

void init()
{
    srand(time(nullptr));
    txrMan->init(window.getRenderer());
    fontMan->init(window.getRenderer(), "fonts/SFPro.otf");

    window.addInputHandler(&handler);
}
void loop()
{
    ElasticSprite sprite;
    sprite.load("textures/elastic.png", 8);
    sprite.setCrop({0, 0, 24, 24});
    sprite.setSize(400, 50);
    sprite.setPos(100, 100);

    Text text;
    text.setMsg("Hihi");
    text.setSize(24);
    text.setPos(200, 200);

    Label label;
    label.setMsg("Tadaaa");
    label.setPos(200, 400);

    Button button;
    button.setMsg("Click me right now~~~");
    button.setPos(400, 400);

    handler.addWidget(&button);
    handler.addWidget(&label);

    while (window.isOpen())
    {
        window.begin();

        sprite.draw(window.getRenderer());
        text.draw(window.getRenderer());

        handler.tick();
        handler.draw(window.getRenderer());

        window.end();
    }
}

*/
