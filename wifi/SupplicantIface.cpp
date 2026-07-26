#include "SupplicantIface.h"

using ::android::hardware::Return;
using ::android::hardware::Void;

namespace android::hardware::wifi::supplicant::V1_0::implementation {

SupplicantIface::SupplicantIface(const std::string& interfaceName)
    : mInterfaceName(interfaceName) {}

// Basic Info
Return<void> SupplicantIface::getName(getName_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status, mInterfaceName);
    return Void();
}

Return<void> SupplicantIface::getType(getType_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status, mNetworkType);
    return Void();
}

// Network Management
Return<void> SupplicantIface::addNetwork(addNetwork_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    android::sp<SupplicantStaNetwork> network = new SupplicantStaNetwork(mNetworks.size(), mInterfaceName, mNetworkType);

    mNetworks.push_back(network);
    _hidl_cb(status, static_cast<android::sp<SupplicantNetwork>>(network));
    return Void();
}

Return<void> SupplicantIface::removeNetwork(SupplicantNetworkId id, removeNetwork_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };

    for (int i = 0; i < mNetworks.size(); i++) {
        if (mNetworks[i]->mNetworkId == id) {
            mNetworks.erase(mNetworks.begin() + i);
            _hidl_cb(status);
            return Void();
        }
    }

    status.code = SupplicantStatusCode::FAILURE_NETWORK_UNKNOWN;
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantIface::getNetwork(SupplicantNetworkId id, getNetwork_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };

    for (int i = 0; i < mNetworks.size(); i++) {
        if (mNetworks[i]->mNetworkId == id) {
            _hidl_cb(status, static_cast<android::sp<SupplicantNetwork>>(mNetworks[i]));
            return Void();
        }
    }

    status.code = SupplicantStatusCode::FAILURE_NETWORK_UNKNOWN;
    _hidl_cb(status, nullptr);
    return Void();
}

Return<void> SupplicantIface::listNetworks(listNetworks_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    std::vector<SupplicantNetworkId> networkIds;

    for (const auto &network : mNetworks) {
        networkIds.push_back(network->mNetworkId);
    }

    _hidl_cb(status, networkIds);
    return Void();
}

// WPS Operations
Return<void> SupplicantIface::setWpsDeviceName(const hidl_string& name, setWpsDeviceName_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantIface::setWpsDeviceType(const hidl_array<uint8_t, 8>& type, setWpsDeviceType_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantIface::setWpsManufacturer(const hidl_string& manufacturer, setWpsManufacturer_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantIface::setWpsModelName(const hidl_string& modelName, setWpsModelName_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantIface::setWpsModelNumber(const hidl_string& modelNumber, setWpsModelNumber_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantIface::setWpsSerialNumber(const hidl_string& serialNumber, setWpsSerialNumber_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantIface::setWpsConfigMethods(hidl_bitfield<WpsConfigMethods> configMethods, setWpsConfigMethods_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

}
