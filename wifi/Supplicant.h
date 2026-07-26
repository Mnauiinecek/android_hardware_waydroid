#pragma once

#include <string>
#include <vector>

#include <android/hardware/wifi/supplicant/1.0/ISupplicant.h>
#include <hidl/Status.h>

using ::android::hardware::Return;

namespace android::hardware::wifi::supplicant::V1_0::implementation {

class Supplicant : public ISupplicant {
public:

    Return<void> getInterface(const ISupplicant::IfaceInfo &ifaceInfo, getInterface_cb _hidl_cb) override;
    Return<void> listInterfaces(listInterfaces_cb _hidl_cb) override;
    Return<void> registerCallback(const sp<ISupplicantCallback> &callback, registerCallback_cb _hidl_cb) override;
    Return<void> setDebugParams(ISupplicant::DebugLevel level, bool showTimestamp, bool showKeys, setDebugParams_cb _hidl_cb) override;
    Return<ISupplicant::DebugLevel> getDebugLevel() override;
    Return<bool> isDebugShowTimestampEnabled() override;
    Return<bool> isDebugShowKeysEnabled() override;
    Return<void> setConcurrencyPriority(IfaceType type, setConcurrencyPriority_cb _hidl_cb) override;
};

}  // namespace android::hardware::wifi::supplicant::V1_0::implementation
