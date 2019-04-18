/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSTestEventConstructor.h"

#include "JSDOMAttribute.h"
#include "JSDOMBinding.h"
#include "JSDOMConstructor.h"
#include "JSDOMConvertBoolean.h"
#include "JSDOMConvertInterface.h"
#include "JSDOMConvertStrings.h"
#include "JSDOMExceptionHandling.h"
#include "JSDOMWrapperCache.h"
#include <runtime/JSCInlines.h>
#include <wtf/GetPtr.h>


namespace WebCore {
using namespace JSC;

template<> TestEventConstructor::Init convertDictionary<TestEventConstructor::Init>(ExecState& state, JSValue value)
{
    VM& vm = state.vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    bool isNullOrUndefined = value.isUndefinedOrNull();
    auto* object = isNullOrUndefined ? nullptr : value.getObject();
    if (UNLIKELY(!isNullOrUndefined && !object)) {
        throwTypeError(&state, throwScope);
        return { };
    }
    TestEventConstructor::Init result;
    JSValue bubblesValue = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "bubbles"));
    if (!bubblesValue.isUndefined()) {
        result.bubbles = convert<IDLBoolean>(state, bubblesValue);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.bubbles = false;
    JSValue cancelableValue = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "cancelable"));
    if (!cancelableValue.isUndefined()) {
        result.cancelable = convert<IDLBoolean>(state, cancelableValue);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.cancelable = false;
    JSValue composedValue = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "composed"));
    if (!composedValue.isUndefined()) {
        result.composed = convert<IDLBoolean>(state, composedValue);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.composed = false;
    JSValue attr2Value = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "attr2"));
    if (!attr2Value.isUndefined()) {
        result.attr2 = convert<IDLDOMString>(state, attr2Value);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.attr2 = emptyString();
    JSValue attr3Value = isNullOrUndefined ? jsUndefined() : object->get(&state, Identifier::fromString(&state, "attr3"));
    if (!attr3Value.isUndefined()) {
        result.attr3 = convert<IDLDOMString>(state, attr3Value);
        RETURN_IF_EXCEPTION(throwScope, { });
    } else
        result.attr3 = emptyString();
    return result;
}

// Attributes

JSC::EncodedJSValue jsTestEventConstructorConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
bool setJSTestEventConstructorConstructor(JSC::ExecState*, JSC::EncodedJSValue, JSC::EncodedJSValue);
JSC::EncodedJSValue jsTestEventConstructorAttr1(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
JSC::EncodedJSValue jsTestEventConstructorAttr2(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
#if ENABLE(SPECIAL_EVENT)
JSC::EncodedJSValue jsTestEventConstructorAttr3(JSC::ExecState*, JSC::EncodedJSValue, JSC::PropertyName);
#endif

class JSTestEventConstructorPrototype : public JSC::JSNonFinalObject {
public:
    using Base = JSC::JSNonFinalObject;
    static JSTestEventConstructorPrototype* create(JSC::VM& vm, JSDOMGlobalObject* globalObject, JSC::Structure* structure)
    {
        JSTestEventConstructorPrototype* ptr = new (NotNull, JSC::allocateCell<JSTestEventConstructorPrototype>(vm.heap)) JSTestEventConstructorPrototype(vm, globalObject, structure);
        ptr->finishCreation(vm);
        return ptr;
    }

    DECLARE_INFO;
    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

private:
    JSTestEventConstructorPrototype(JSC::VM& vm, JSC::JSGlobalObject*, JSC::Structure* structure)
        : JSC::JSNonFinalObject(vm, structure)
    {
    }

    void finishCreation(JSC::VM&);
};

using JSTestEventConstructorConstructor = JSDOMConstructor<JSTestEventConstructor>;

template<> EncodedJSValue JSC_HOST_CALL JSTestEventConstructorConstructor::construct(ExecState* state)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    UNUSED_PARAM(throwScope);
    auto* castedThis = jsCast<JSTestEventConstructorConstructor*>(state->jsCallee());
    ASSERT(castedThis);
    if (UNLIKELY(state->argumentCount() < 1))
        return throwVMError(state, throwScope, createNotEnoughArgumentsError(state));
    auto type = convert<IDLDOMString>(*state, state->uncheckedArgument(0));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto eventInitDict = convert<IDLDictionary<TestEventConstructor::Init>>(*state, state->argument(1));
    RETURN_IF_EXCEPTION(throwScope, encodedJSValue());
    auto object = TestEventConstructor::create(WTFMove(type), WTFMove(eventInitDict));
    return JSValue::encode(toJSNewlyCreated<IDLInterface<TestEventConstructor>>(*state, *castedThis->globalObject(), WTFMove(object)));
}

template<> JSValue JSTestEventConstructorConstructor::prototypeForStructure(JSC::VM& vm, const JSDOMGlobalObject& globalObject)
{
    return JSEvent::getConstructor(vm, &globalObject);
}

template<> void JSTestEventConstructorConstructor::initializeProperties(VM& vm, JSDOMGlobalObject& globalObject)
{
    putDirect(vm, vm.propertyNames->prototype, JSTestEventConstructor::prototype(vm, globalObject), JSC::PropertyAttribute::DontDelete | JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->name, jsNontrivialString(&vm, String(ASCIILiteral("TestEventConstructor"))), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
    putDirect(vm, vm.propertyNames->length, jsNumber(1), JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::DontEnum);
}

template<> const ClassInfo JSTestEventConstructorConstructor::s_info = { "TestEventConstructor", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestEventConstructorConstructor) };

/* Hash table for prototype */

static const HashTableValue JSTestEventConstructorPrototypeTableValues[] =
{
    { "constructor", static_cast<unsigned>(JSC::PropertyAttribute::DontEnum), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestEventConstructorConstructor), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(setJSTestEventConstructorConstructor) } },
    { "attr1", static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestEventConstructorAttr1), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
    { "attr2", static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestEventConstructorAttr2), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
#if ENABLE(SPECIAL_EVENT)
    { "attr3", static_cast<unsigned>(JSC::PropertyAttribute::ReadOnly | JSC::PropertyAttribute::CustomAccessor | JSC::PropertyAttribute::DOMAttribute), NoIntrinsic, { (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestEventConstructorAttr3), (intptr_t) static_cast<PutPropertySlot::PutValueFunc>(0) } },
#else
    { 0, 0, NoIntrinsic, { 0, 0 } },
#endif
};

const ClassInfo JSTestEventConstructorPrototype::s_info = { "TestEventConstructorPrototype", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestEventConstructorPrototype) };

void JSTestEventConstructorPrototype::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    reifyStaticProperties(vm, JSTestEventConstructor::info(), JSTestEventConstructorPrototypeTableValues, *this);
}

const ClassInfo JSTestEventConstructor::s_info = { "TestEventConstructor", &Base::s_info, nullptr, nullptr, CREATE_METHOD_TABLE(JSTestEventConstructor) };

JSTestEventConstructor::JSTestEventConstructor(Structure* structure, JSDOMGlobalObject& globalObject, Ref<TestEventConstructor>&& impl)
    : JSEvent(structure, globalObject, WTFMove(impl))
{
}

void JSTestEventConstructor::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(vm, info()));

}

JSObject* JSTestEventConstructor::createPrototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSTestEventConstructorPrototype::create(vm, &globalObject, JSTestEventConstructorPrototype::createStructure(vm, &globalObject, JSEvent::prototype(vm, globalObject)));
}

JSObject* JSTestEventConstructor::prototype(VM& vm, JSDOMGlobalObject& globalObject)
{
    return getDOMPrototype<JSTestEventConstructor>(vm, globalObject);
}

JSValue JSTestEventConstructor::getConstructor(VM& vm, const JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestEventConstructorConstructor>(vm, *jsCast<const JSDOMGlobalObject*>(globalObject));
}

template<> inline JSTestEventConstructor* IDLAttribute<JSTestEventConstructor>::cast(ExecState& state, EncodedJSValue thisValue)
{
    return jsDynamicDowncast<JSTestEventConstructor*>(state.vm(), JSValue::decode(thisValue));
}

EncodedJSValue jsTestEventConstructorConstructor(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicDowncast<JSTestEventConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype))
        return throwVMTypeError(state, throwScope);
    return JSValue::encode(JSTestEventConstructor::getConstructor(state->vm(), prototype->globalObject()));
}

bool setJSTestEventConstructorConstructor(ExecState* state, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    VM& vm = state->vm();
    auto throwScope = DECLARE_THROW_SCOPE(vm);
    auto* prototype = jsDynamicDowncast<JSTestEventConstructorPrototype*>(vm, JSValue::decode(thisValue));
    if (UNLIKELY(!prototype)) {
        throwVMTypeError(state, throwScope);
        return false;
    }
    // Shadowing a built-in constructor
    return prototype->putDirect(vm, vm.propertyNames->constructor, JSValue::decode(encodedValue));
}

static inline JSValue jsTestEventConstructorAttr1Getter(ExecState& state, JSTestEventConstructor& thisObject, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(state);
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLDOMString>(state, throwScope, impl.attr1());
    return result;
}

EncodedJSValue jsTestEventConstructorAttr1(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestEventConstructor>::get<jsTestEventConstructorAttr1Getter, CastedThisErrorBehavior::Assert>(*state, thisValue, "attr1");
}

static inline JSValue jsTestEventConstructorAttr2Getter(ExecState& state, JSTestEventConstructor& thisObject, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(state);
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLDOMString>(state, throwScope, impl.attr2());
    return result;
}

EncodedJSValue jsTestEventConstructorAttr2(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestEventConstructor>::get<jsTestEventConstructorAttr2Getter, CastedThisErrorBehavior::Assert>(*state, thisValue, "attr2");
}

#if ENABLE(SPECIAL_EVENT)
static inline JSValue jsTestEventConstructorAttr3Getter(ExecState& state, JSTestEventConstructor& thisObject, ThrowScope& throwScope)
{
    UNUSED_PARAM(throwScope);
    UNUSED_PARAM(state);
    auto& impl = thisObject.wrapped();
    JSValue result = toJS<IDLDOMString>(state, throwScope, impl.attr3());
    return result;
}

EncodedJSValue jsTestEventConstructorAttr3(ExecState* state, EncodedJSValue thisValue, PropertyName)
{
    return IDLAttribute<JSTestEventConstructor>::get<jsTestEventConstructorAttr3Getter, CastedThisErrorBehavior::Assert>(*state, thisValue, "attr3");
}

#endif

#if ENABLE(BINDING_INTEGRITY)
#if PLATFORM(WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestEventConstructor@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore20TestEventConstructorE[]; }
#endif
#endif

JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject* globalObject, Ref<TestEventConstructor>&& impl)
{

#if ENABLE(BINDING_INTEGRITY)
    void* actualVTablePointer = *(reinterpret_cast<void**>(impl.ptr()));
#if PLATFORM(WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestEventConstructor@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore20TestEventConstructorE[2];
#endif

    // If this fails TestEventConstructor does not have a vtable, so you need to add the
    // ImplementationLacksVTable attribute to the interface definition
    static_assert(std::is_polymorphic<TestEventConstructor>::value, "TestEventConstructor is not polymorphic");

    // If you hit this assertion you either have a use after free bug, or
    // TestEventConstructor has subclasses. If TestEventConstructor has subclasses that get passed
    // to toJS() we currently require TestEventConstructor you to opt out of binding hardening
    // by adding the SkipVTableValidation attribute to the interface IDL definition
    RELEASE_ASSERT(actualVTablePointer == expectedVTablePointer);
#endif
    return createWrapper<TestEventConstructor>(globalObject, WTFMove(impl));
}

JSC::JSValue toJS(JSC::ExecState* state, JSDOMGlobalObject* globalObject, TestEventConstructor& impl)
{
    return wrap(state, globalObject, impl);
}


}