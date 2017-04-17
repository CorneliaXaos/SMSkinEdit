#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <FL/Fl_Widget.H>

#include "control/controls.h"
#include "enums.h"
#include "gui/widgets/TextureSelectorWidget.h"

// Constants
static const char* selectedBody = "B";
static const char* selectedHead = "H";
static const char* labelDiffuse = "Diffuse";
static const char* labelEmissive = "Emissive";
static const char* CALLBACK_ID = "TextureSelectorWidget";

// Namespace Shortenings
namespace controls = smskinedit::control::controls;

// Using Declarations
using ModelType = smskinedit::enums::ModelType;
using TextureType = smskinedit::enums::TextureType;
using EventFlag = smskinedit::control::EventFlag;
using TextureControl = smskinedit::control::TextureControl;

namespace smskinedit {
    namespace gui {

        // Constructor
        TextureSelectorWidget::TextureSelectorWidget(int x, int y, int width,
                int height) : Fl_Group{x, y, width, height},
                _toggleButton(nullptr), _radioButtonDiffuse(nullptr),
                _radioButtonEmissive(nullptr) {

            // Init self & helpers
            box(FL_THIN_DOWN_BOX);
            int childWidth = (width - height) / 2;

            // Init _toggleButton
            _toggleButton = new Fl_Button{x, y, height, height, selectedBody};
            _toggleButton->visible_focus(false);
            _toggleButton->callback([](Fl_Widget*, void*) {
                ModelType type = controls::textureControl.getModelType();
                type = (type == ModelType::BODY)
                        ? ModelType::HEAD : ModelType::BODY;
                controls::textureControl.setModelType(type);
            }, nullptr);

            // Init _radioButtonDiffuse
            _radioButtonDiffuse = new Fl_Radio_Round_Button{x + height, y,
                    childWidth, height, labelDiffuse};
            _radioButtonDiffuse->visible_focus(false);
            _radioButtonDiffuse->box(FL_THIN_DOWN_BOX);
            _radioButtonDiffuse->setonly();
            _radioButtonDiffuse->callback([](Fl_Widget*, void*) {
                controls::textureControl.setTextureType(TextureType::DIFFUSE);
            }, nullptr);

            // Init _radioButtonEmissive
            _radioButtonEmissive = new Fl_Radio_Round_Button{x + height
                    + childWidth, y, childWidth, height, labelEmissive};
            _radioButtonEmissive->visible_focus(false);
            _radioButtonEmissive->box(FL_THIN_DOWN_BOX);
            _radioButtonEmissive->callback([](Fl_Widget*, void*) {
                controls::textureControl.setTextureType(TextureType::EMISSIVE);
            }, nullptr);

            // Callbacks
            controls::textureControl.addCallback(CALLBACK_ID,
                    [&](EventFlag event) {
                if (event == TextureControl::MODEL_TYPE_CHANGED) {
                    if (controls::textureControl.getModelType() ==
                            ModelType::BODY) {
                        _toggleButton->label(selectedBody);
                    } else {
                        _toggleButton->label(selectedHead);
                    }
                    _toggleButton->redraw();
                }
            });

            // Finish Up
            end();
        }
        TextureSelectorWidget::~TextureSelectorWidget() {
            if (_toggleButton) {
                delete _toggleButton;
                _toggleButton = nullptr;
            }
            if (_radioButtonDiffuse) {
                delete _radioButtonDiffuse;
                _radioButtonDiffuse = nullptr;
            }
            if (_radioButtonEmissive) {
                delete _radioButtonEmissive;
                _radioButtonEmissive = nullptr;
            }
        }
    }
}
