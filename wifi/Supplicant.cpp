#include "Supplicant.h"
#include "SupplicantStaIface.h"

using ::android::hardware::Return;
using ::android::hardware::Void;

namespace android::hardware::wifi::supplicant::V1_0::implementation {

Return<void> Supplicant::getInterface(const ISupplicant::IfaceInfo &ifaceInfo, getInterface_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    android::sp<ISupplicantStaIface> iface = new SupplicantStaIface(ifaceInfo.name);

    _hidl_cb(status, iface);

    return Void();
}

Return<void> Supplicant::listInterfaces(listInterfaces_cb _hidl_cb) {
    // 1. Create the success status
    SupplicantStatus status = {
        .code = SupplicantStatusCode::SUCCESS,
        .debugMessage = ""
    };

    // 2. Create a standard C++ vector to hold your fake interfaces
    std::vector<ISupplicant::IfaceInfo> fakeInterfaces;

    // 3. Create your fake interface data
    ISupplicant::IfaceInfo myWlan = {
        .type = IfaceType::STA,  // STA means "Station" (a standard Wi-Fi client)
        .name = "wlan0"          // The name Android expects
    };

    // 4. Add it to the vector
    fakeInterfaces.push_back(myWlan);

    // 5. Pass it back via the callback. 
    // The C++ compiler will automatically convert your std::vector 
    // into the required hidl_vec<IfaceInfo> for you!
    _hidl_cb(status, fakeInterfaces);

    return Void();
}

Return<void> Supplicant::registerCallback(const sp<ISupplicantCallback> &callback, registerCallback_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = ""};
    _hidl_cb(status);
    return Void();
}

// Debug methods
Return<void> Supplicant::setDebugParams(ISupplicant::DebugLevel /* level */, bool /* showTimestamp */, bool /* showKeys */, setDebugParams_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<ISupplicant::DebugLevel> Supplicant::getDebugLevel() {
    return ISupplicant::DebugLevel::INFO;
}

Return<bool> Supplicant::isDebugShowTimestampEnabled() {
    return false;
}

Return<bool> Supplicant::isDebugShowKeysEnabled() {
    return false;
}

Return<void> Supplicant::setConcurrencyPriority(IfaceType /* type */, setConcurrencyPriority_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

}
