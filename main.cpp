  #include <nan.h>
  using namespace std;
  using namespace Nan;
  using namespace v8;
  #include <stdint.h>
  #include <vector>

NAN_METHOD(aabb) {
    
    //Отримую фігури з JS
    v8::Local<v8::Object> firstFigure = info[0]->ToObject();
    v8::Local<v8::Object> secondFigure = info[1]->ToObject();

    v8::Local<v8::String> firstFigureXFromJS = Nan::New("firstFigureX").ToLocalChecked();
    v8::Local<v8::String> firstFigureYFromJS = Nan::New("firstFigureY").ToLocalChecked();
    v8::Local<v8::String> firstFigureWidthFromJS = Nan::New("firstFigureWidth").ToLocalChecked();
    v8::Local<v8::String> firstFigureHeightFromJS = Nan::New("firstFigureHeight").ToLocalChecked();
    v8::Local<v8::String> secondFigureXFromJS = Nan::New("secondFigureX").ToLocalChecked();
    v8::Local<v8::String> secondFigureYFromJS = Nan::New("secondFigureY").ToLocalChecked();
    v8::Local<v8::String> secondFigureWidthFromJS= Nan::New("secondFigureWidth").ToLocalChecked();
    v8::Local<v8::String> secondFigureHeightFromJS = Nan::New("secondFigureHeight").ToLocalChecked();

    double firstFigureX = 0;
    double firstFigureY = 0;
    double firstFigureWidth = 0;
    double firstFigureHeight = 0;
    double secondFigureX = 0;
    double secondFigureY = 0;
    double secondFigureWidth = 0;
    double secondFigureHeight = 0;

    if (Nan::HasOwnProperty(firstFigure, firstFigureXFromJS).FromJust()) {
        v8::Local<v8::Value> value = (Nan::Get(firstFigure, firstFigureXFromJS).ToLocalChecked());
        firstFigureX = value->NumberValue();
    }

    if (Nan::HasOwnProperty(firstFigure, firstFigureYFromJS).FromJust()) {
        v8::Local<v8::Value> value = Nan::Get(firstFigure, firstFigureYFromJS).ToLocalChecked();
        firstFigureY = value->NumberValue();
    }

    if (Nan::HasOwnProperty(firstFigure, firstFigureWidthFromJS).FromJust()) {
        v8::Local<v8::Value> value = Nan::Get(firstFigure, firstFigureWidthFromJS).ToLocalChecked();
        firstFigureWidth = value->NumberValue();
    }

    if (Nan::HasOwnProperty(firstFigure, firstFigureHeightFromJS).FromJust()) {
        v8::Local<v8::Value> value = Nan::Get(firstFigure, firstFigureHeightFromJS).ToLocalChecked();
        firstFigureHeight = value->NumberValue();
    }

    if (Nan::HasOwnProperty(secondFigure, secondFigureXFromJS).FromJust()) {
        v8::Local<v8::Value> value = Nan::Get(secondFigure, secondFigureXFromJS).ToLocalChecked();
        secondFigureX = value->NumberValue();
    }

    if (Nan::HasOwnProperty(secondFigure, secondFigureYFromJS).FromJust()) {
        v8::Local<v8::Value> value = Nan::Get(secondFigure, secondFigureYFromJS).ToLocalChecked();
        secondFigureY = value->NumberValue();
    }

    if (Nan::HasOwnProperty(secondFigure, secondFigureWidthFromJS).FromJust()) {
        v8::Local<v8::Value> value = Nan::Get(secondFigure, secondFigureWidthFromJS).ToLocalChecked();
        secondFigureWidth = value->NumberValue();
    }

    if (Nan::HasOwnProperty(secondFigure, secondFigureHeightFromJS).FromJust()) {
        v8::Local<v8::Value> value = Nan::Get(secondFigure, secondFigureHeightFromJS).ToLocalChecked();
        secondFigureHeight = value->NumberValue();
    }

    bool result = false;

    if(firstFigureX < secondFigureX + secondFigureWidth &&
       firstFigureX + firstFigureWidth > secondFigureX &&
       firstFigureY < secondFigureY + secondFigureHeight &&
       firstFigureY + firstFigureHeight > secondFigureY){
       result = true;
    };
    
    info.GetReturnValue().Set(Nan::New(result));
}

NAN_MODULE_INIT(Initialize) {
    NAN_EXPORT(target, aabb);
}

NODE_MODULE(addon, Initialize);
    