#ifndef __NODE_GDAL_LYR_FIELD_DEFN_COLLECTION_H__
#define __NODE_GDAL_LYR_FIELD_DEFN_COLLECTION_H__

// node
#include <node.h>
#include <node_object_wrap.h>

// nan
#include "../nan-wrapper.h"

// gdal
#include <gdal_priv.h>

using namespace v8;
using namespace node;

// Layer.fields : LayerFields

// Identical to FeatureDefn.fields object from the outside
// but on the inside it uses the parent layer
// to create/modify fields instead of illegally
// adding them directly to the layer definition

namespace node_gdal {

class LayerFields : public Nan::ObjectWrap {
    public:
  static Nan::Persistent<FunctionTemplate> constructor;

  static void Initialize(Local<Object> target);
  static NAN_METHOD(New);
  static Local<Value> New(Local<Value> layer_obj);
  static NAN_METHOD(toString);

  static NAN_METHOD(get);
  static NAN_METHOD(getNames);
  static NAN_METHOD(count);
  static NAN_METHOD(add);
  static NAN_METHOD(remove);
  static NAN_METHOD(indexOf);
  static NAN_METHOD(reorder);

  // - implement in the future -
  // static NAN_METHOD(alter);

  static NAN_GETTER(layerGetter);

  LayerFields();

    private:
  ~LayerFields();
};

} // namespace node_gdal
#endif
