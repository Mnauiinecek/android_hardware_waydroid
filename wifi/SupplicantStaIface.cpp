#include <array>
#include <android/log.h>
#include <utils/Log.h>

#include "SupplicantStaIface.h"

using ::android::hardware::Return;
using ::android::hardware::Void;

namespace android::hardware::wifi::supplicant::V1_0::implementation {

// Basic Info
Return<void> SupplicantStaIface::getName(getName_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status, mInterfaceName);
    return Void();
}

Return<void> SupplicantStaIface::getType(getType_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status, mNetworkType);
    return Void();
}

// Network Management
Return<void> SupplicantStaIface::addNetwork(addNetwork_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    android::sp<SupplicantStaNetwork> network = new SupplicantStaNetwork(mNetworks.size(), mInterfaceName, mNetworkType);

    mNetworks.push_back(network);
    _hidl_cb(status, static_cast<android::sp<SupplicantNetwork>>(network));
    return Void();
}

Return<void> SupplicantStaIface::removeNetwork(SupplicantNetworkId id, removeNetwork_cb _hidl_cb) {
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

Return<void> SupplicantStaIface::getNetwork(SupplicantNetworkId id, getNetwork_cb _hidl_cb) {
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

Return<void> SupplicantStaIface::listNetworks(listNetworks_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    std::vector<SupplicantNetworkId> networkIds;

    for (const auto &network : mNetworks) {
        networkIds.push_back(network->mNetworkId);
    }

    _hidl_cb(status, networkIds);
    return Void();
}

// WPS Operations
Return<void> SupplicantStaIface::setWpsDeviceName(const hidl_string& name, setWpsDeviceName_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setWpsDeviceType(const hidl_array<uint8_t, 8>& type, setWpsDeviceType_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setWpsManufacturer(const hidl_string& manufacturer, setWpsManufacturer_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setWpsModelName(const hidl_string& modelName, setWpsModelName_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setWpsModelNumber(const hidl_string& modelNumber, setWpsModelNumber_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setWpsSerialNumber(const hidl_string& serialNumber, setWpsSerialNumber_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setWpsConfigMethods(hidl_bitfield<WpsConfigMethods> configMethods, setWpsConfigMethods_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::registerCallback(const android::sp<ISupplicantStaIfaceCallback>& callback, registerCallback_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };

    mCallback = callback;

    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::reassociate(reassociate_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    ALOGE("reassociate");
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::reconnect(reconnect_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    ALOGE("reconnect");

    if (mNetworks.size() > 0 && mNetworks[0]->mIsEnabled) {
        android::sp<SupplicantStaNetwork> networkToConnect = mNetworks[0];

        mCallback->onStateChanged(ISupplicantStaIfaceCallback::State::ASSOCIATED, networkToConnect->mBssid, networkToConnect->mNetworkId, networkToConnect->mSsid);
        mCallback->onStateChanged(ISupplicantStaIfaceCallback::State::GROUP_HANDSHAKE, networkToConnect->mBssid, networkToConnect->mNetworkId, networkToConnect->mSsid);
        mCallback->onStateChanged(ISupplicantStaIfaceCallback::State::COMPLETED, networkToConnect->mBssid, networkToConnect->mNetworkId, networkToConnect->mSsid);
    }

    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::disconnect(disconnect_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    ALOGE("disconnect");
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setPowerSave(bool /* enable */, setPowerSave_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::initiateTdlsDiscover(const android::hardware::hidl_array<uint8_t, 6>& /* macAddress */, initiateTdlsDiscover_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::initiateTdlsSetup(const android::hardware::hidl_array<uint8_t, 6>& /* macAddress */, initiateTdlsSetup_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::initiateTdlsTeardown(const android::hardware::hidl_array<uint8_t, 6>& /* macAddress */, initiateTdlsTeardown_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::initiateAnqpQuery(const android::hardware::hidl_array<uint8_t, 6>& /* macAddress */, const android::hardware::hidl_vec<ISupplicantStaIface::AnqpInfoId>& /* infoElements */, const android::hardware::hidl_vec<ISupplicantStaIface::Hs20AnqpSubtypes>& /* subTypes */, initiateAnqpQuery_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::initiateHs20IconQuery(const android::hardware::hidl_array<uint8_t, 6>& /* macAddress */, const android::hardware::hidl_string& /* fileName */, initiateHs20IconQuery_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::getMacAddress(getMacAddress_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    std::array<uint8_t, 6> mac = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55};
    _hidl_cb(status, mac);
    return Void();
}

Return<void> SupplicantStaIface::startRxFilter(startRxFilter_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::stopRxFilter(stopRxFilter_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::addRxFilter(ISupplicantStaIface::RxFilterType /* type */, addRxFilter_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::removeRxFilter(ISupplicantStaIface::RxFilterType /* type */, removeRxFilter_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setBtCoexistenceMode(ISupplicantStaIface::BtCoexistenceMode /* mode */, setBtCoexistenceMode_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setBtCoexistenceScanModeEnabled(bool /* enable */, setBtCoexistenceScanModeEnabled_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setSuspendModeEnabled(bool /* enable */, setSuspendModeEnabled_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setCountryCode(const android::hardware::hidl_array<int8_t, 2>& /* code */, setCountryCode_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::startWpsRegistrar(const android::hardware::hidl_array<uint8_t, 6>& /* bssid */, const android::hardware::hidl_string& /* pin */, startWpsRegistrar_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::startWpsPbc(const android::hardware::hidl_array<uint8_t, 6>& /* bssid */, startWpsPbc_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::startWpsPinKeypad(const android::hardware::hidl_string& /* pin */, startWpsPinKeypad_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::startWpsPinDisplay(const android::hardware::hidl_array<uint8_t, 6>& /* bssid */, startWpsPinDisplay_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status, "12345678");
    return Void();
}

Return<void> SupplicantStaIface::cancelWps(cancelWps_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::setExternalSim(bool /* useExternalSim */, setExternalSim_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::addExtRadioWork(const android::hardware::hidl_string& /* name */, uint32_t /* freqInMhz */, uint32_t /* timeoutInSec */, addExtRadioWork_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status, 1);
    return Void();
}

Return<void> SupplicantStaIface::removeExtRadioWork(uint32_t /* id */, removeExtRadioWork_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

Return<void> SupplicantStaIface::enableAutoReconnect(bool /* enable */, enableAutoReconnect_cb _hidl_cb) {
    SupplicantStatus status = { .code = SupplicantStatusCode::SUCCESS, .debugMessage = "" };
    _hidl_cb(status);
    return Void();
}

}
