#include "SupplicantStaNetwork.h"

namespace android::hardware::wifi::supplicant::V1_0::implementation {

Return<void> SupplicantStaNetwork::registerCallback(const sp<ISupplicantStaNetworkCallback>&, registerCallback_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

// --- Setters ---
Return<void> SupplicantStaNetwork::setSsid(const hidl_vec<uint8_t>& ssid, setSsid_cb _hidl_cb) {
    mSsid = ssid;

    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setBssid(const hidl_array<uint8_t, 6>& bssid, setBssid_cb _hidl_cb) {
    mBssid = bssid;

    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setScanSsid(bool, setScanSsid_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setKeyMgmt(hidl_bitfield<KeyMgmtMask>, setKeyMgmt_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setProto(hidl_bitfield<ProtoMask>, setProto_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setAuthAlg(hidl_bitfield<AuthAlgMask>, setAuthAlg_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setGroupCipher(hidl_bitfield<GroupCipherMask>, setGroupCipher_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setPairwiseCipher(hidl_bitfield<PairwiseCipherMask>, setPairwiseCipher_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setPskPassphrase(const hidl_string& psk, setPskPassphrase_cb _hidl_cb) {
    mPskPassphrase = psk;
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setPsk(const hidl_array<uint8_t, 32>&, setPsk_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setWepKey(uint32_t, const hidl_vec<uint8_t>&, setWepKey_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setWepTxKeyIdx(uint32_t, setWepTxKeyIdx_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setRequirePmf(bool, setRequirePmf_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapMethod(EapMethod, setEapMethod_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapPhase2Method(EapPhase2Method, setEapPhase2Method_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapIdentity(const hidl_vec<uint8_t>&, setEapIdentity_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapAnonymousIdentity(const hidl_vec<uint8_t>&, setEapAnonymousIdentity_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapPassword(const hidl_vec<uint8_t>&, setEapPassword_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapCACert(const hidl_string&, setEapCACert_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapCAPath(const hidl_string&, setEapCAPath_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapClientCert(const hidl_string&, setEapClientCert_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapPrivateKeyId(const hidl_string&, setEapPrivateKeyId_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapSubjectMatch(const hidl_string&, setEapSubjectMatch_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapAltSubjectMatch(const hidl_string&, setEapAltSubjectMatch_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapEngine(bool, setEapEngine_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapEngineID(const hidl_string&, setEapEngineID_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setEapDomainSuffixMatch(const hidl_string&, setEapDomainSuffixMatch_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setProactiveKeyCaching(bool, setProactiveKeyCaching_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setIdStr(const hidl_string& idStr, setIdStr_cb _hidl_cb) {
    mIdStr = idStr;

    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::setUpdateIdentifier(uint32_t, setUpdateIdentifier_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

// --- Getters ---
Return<void> SupplicantStaNetwork::getSsid(getSsid_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, mSsid);
    return Void();
}

Return<void> SupplicantStaNetwork::getBssid(getBssid_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, mBssid);
    return Void();
}

Return<void> SupplicantStaNetwork::getScanSsid(getScanSsid_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, false);
    return Void();
}

Return<void> SupplicantStaNetwork::getKeyMgmt(getKeyMgmt_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, 0);
    return Void();
}

Return<void> SupplicantStaNetwork::getProto(getProto_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, 0);
    return Void();
}

Return<void> SupplicantStaNetwork::getAuthAlg(getAuthAlg_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, 0);
    return Void();
}

Return<void> SupplicantStaNetwork::getGroupCipher(getGroupCipher_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, 0);
    return Void();
}

Return<void> SupplicantStaNetwork::getPairwiseCipher(getPairwiseCipher_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, 0);
    return Void();
}

Return<void> SupplicantStaNetwork::getPskPassphrase(getPskPassphrase_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, mPskPassphrase);
    return Void();
}

Return<void> SupplicantStaNetwork::getPsk(getPsk_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, {});
    return Void();
}

Return<void> SupplicantStaNetwork::getWepKey(uint32_t, getWepKey_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, {});
    return Void();
}

Return<void> SupplicantStaNetwork::getWepTxKeyIdx(getWepTxKeyIdx_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, 0);
    return Void();
}

Return<void> SupplicantStaNetwork::getRequirePmf(getRequirePmf_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, false);
    return Void();
}

Return<void> SupplicantStaNetwork::getEapMethod(getEapMethod_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, EapMethod::PEAP);
    return Void();
}

Return<void> SupplicantStaNetwork::getEapPhase2Method(getEapPhase2Method_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, EapPhase2Method::NONE);
    return Void();
}

Return<void> SupplicantStaNetwork::getEapIdentity(getEapIdentity_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, {});
    return Void();
}

Return<void> SupplicantStaNetwork::getEapAnonymousIdentity(getEapAnonymousIdentity_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, {});
    return Void();
}

Return<void> SupplicantStaNetwork::getEapPassword(getEapPassword_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, {});
    return Void();
}

Return<void> SupplicantStaNetwork::getEapCACert(getEapCACert_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, "");
    return Void();
}

Return<void> SupplicantStaNetwork::getEapCAPath(getEapCAPath_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, "");
    return Void();
}

Return<void> SupplicantStaNetwork::getEapClientCert(getEapClientCert_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, "");
    return Void();
}

Return<void> SupplicantStaNetwork::getEapPrivateKeyId(getEapPrivateKeyId_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, "");
    return Void();
}

Return<void> SupplicantStaNetwork::getEapSubjectMatch(getEapSubjectMatch_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, "");
    return Void();
}

Return<void> SupplicantStaNetwork::getEapAltSubjectMatch(getEapAltSubjectMatch_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, "");
    return Void();
}

Return<void> SupplicantStaNetwork::getEapEngine(getEapEngine_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, false);
    return Void();
}

Return<void> SupplicantStaNetwork::getEapEngineID(getEapEngineID_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, "");
    return Void();
}

Return<void> SupplicantStaNetwork::getEapDomainSuffixMatch(getEapDomainSuffixMatch_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, "");
    return Void();
}

Return<void> SupplicantStaNetwork::getIdStr(getIdStr_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, mIdStr);
    return Void();
}

Return<void> SupplicantStaNetwork::getWpsNfcConfigurationToken(getWpsNfcConfigurationToken_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""}, {});
    return Void();
}

// --- Actions & Handlers ---
Return<void> SupplicantStaNetwork::enable(bool noConnect, enable_cb _hidl_cb) {
    mIsEnabled = true;
    if (!noConnect) {
        // Trigger auto-connect sequence here if applicable
    }
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::disable(disable_cb _hidl_cb) {
    mIsEnabled = false;
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::select(select_cb _hidl_cb) {
    mIsEnabled = true;
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::sendNetworkEapSimGsmAuthResponse(const hidl_vec<NetworkResponseEapSimGsmAuthParams>&, sendNetworkEapSimGsmAuthResponse_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::sendNetworkEapSimGsmAuthFailure(sendNetworkEapSimGsmAuthFailure_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::sendNetworkEapSimUmtsAuthResponse(const NetworkResponseEapSimUmtsAuthParams&, sendNetworkEapSimUmtsAuthResponse_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::sendNetworkEapSimUmtsAutsResponse(const hidl_array<uint8_t, 14>&, sendNetworkEapSimUmtsAutsResponse_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::sendNetworkEapSimUmtsAuthFailure(sendNetworkEapSimUmtsAuthFailure_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

Return<void> SupplicantStaNetwork::sendNetworkEapIdentityResponse(const hidl_vec<uint8_t>&, sendNetworkEapIdentityResponse_cb _hidl_cb) {
    _hidl_cb({SupplicantStatusCode::SUCCESS, ""});
    return Void();
}

} // namespace android
