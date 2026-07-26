#pragma once

#include <array>
#include <vector>

#include <android/hardware/wifi/supplicant/1.0/ISupplicantStaNetwork.h>

#include "SupplicantNetwork.h"

namespace android::hardware::wifi::supplicant::V1_0::implementation {

class SupplicantStaNetwork : public SupplicantNetwork, public ISupplicantStaNetwork {
public:
    using SupplicantNetwork::SupplicantNetwork;

    Return<void> getId(getId_cb _hidl_cb) override { return SupplicantNetwork::getId(_hidl_cb); }
    Return<void> getInterfaceName(getInterfaceName_cb _hidl_cb) override { return SupplicantNetwork::getInterfaceName(_hidl_cb); }
    Return<void> getType(getType_cb _hidl_cb) override { return SupplicantNetwork::getType(_hidl_cb); }

    // Base Interface & Identification
    bool isRemote() const override { return false; }
    Return<void> registerCallback(const sp<ISupplicantStaNetworkCallback>& callback, registerCallback_cb _hidl_cb) override;

    // Setters
    Return<void> setSsid(const hidl_vec<uint8_t>& ssid, setSsid_cb _hidl_cb) override;
    Return<void> setBssid(const hidl_array<uint8_t, 6>& bssid, setBssid_cb _hidl_cb) override;
    Return<void> setScanSsid(bool enable, setScanSsid_cb _hidl_cb) override;
    Return<void> setKeyMgmt(hidl_bitfield<KeyMgmtMask> keyMgmtMask, setKeyMgmt_cb _hidl_cb) override;
    Return<void> setProto(hidl_bitfield<ProtoMask> protoMask, setProto_cb _hidl_cb) override;
    Return<void> setAuthAlg(hidl_bitfield<AuthAlgMask> authAlgMask, setAuthAlg_cb _hidl_cb) override;
    Return<void> setGroupCipher(hidl_bitfield<GroupCipherMask> groupCipherMask, setGroupCipher_cb _hidl_cb) override;
    Return<void> setPairwiseCipher(hidl_bitfield<PairwiseCipherMask> pairwiseCipherMask, setPairwiseCipher_cb _hidl_cb) override;
    Return<void> setPskPassphrase(const hidl_string& psk, setPskPassphrase_cb _hidl_cb) override;
    Return<void> setPsk(const hidl_array<uint8_t, 32>& psk, setPsk_cb _hidl_cb) override;
    Return<void> setWepKey(uint32_t keyIdx, const hidl_vec<uint8_t>& wepKey, setWepKey_cb _hidl_cb) override;
    Return<void> setWepTxKeyIdx(uint32_t keyIdx, setWepTxKeyIdx_cb _hidl_cb) override;
    Return<void> setRequirePmf(bool enable, setRequirePmf_cb _hidl_cb) override;
    Return<void> setEapMethod(EapMethod method, setEapMethod_cb _hidl_cb) override;
    Return<void> setEapPhase2Method(EapPhase2Method method, setEapPhase2Method_cb _hidl_cb) override;
    Return<void> setEapIdentity(const hidl_vec<uint8_t>& identity, setEapIdentity_cb _hidl_cb) override;
    Return<void> setEapAnonymousIdentity(const hidl_vec<uint8_t>& identity, setEapAnonymousIdentity_cb _hidl_cb) override;
    Return<void> setEapPassword(const hidl_vec<uint8_t>& password, setEapPassword_cb _hidl_cb) override;
    Return<void> setEapCACert(const hidl_string& path, setEapCACert_cb _hidl_cb) override;
    Return<void> setEapCAPath(const hidl_string& path, setEapCAPath_cb _hidl_cb) override;
    Return<void> setEapClientCert(const hidl_string& path, setEapClientCert_cb _hidl_cb) override;
    Return<void> setEapPrivateKeyId(const hidl_string& id, setEapPrivateKeyId_cb _hidl_cb) override;
    Return<void> setEapSubjectMatch(const hidl_string& match, setEapSubjectMatch_cb _hidl_cb) override;
    Return<void> setEapAltSubjectMatch(const hidl_string& match, setEapAltSubjectMatch_cb _hidl_cb) override;
    Return<void> setEapEngine(bool enable, setEapEngine_cb _hidl_cb) override;
    Return<void> setEapEngineID(const hidl_string& id, setEapEngineID_cb _hidl_cb) override;
    Return<void> setEapDomainSuffixMatch(const hidl_string& match, setEapDomainSuffixMatch_cb _hidl_cb) override;
    Return<void> setProactiveKeyCaching(bool enable, setProactiveKeyCaching_cb _hidl_cb) override;
    Return<void> setIdStr(const hidl_string& idStr, setIdStr_cb _hidl_cb) override;
    Return<void> setUpdateIdentifier(uint32_t id, setUpdateIdentifier_cb _hidl_cb) override;

    // Getters
    Return<void> getSsid(getSsid_cb _hidl_cb) override;
    Return<void> getBssid(getBssid_cb _hidl_cb) override;
    Return<void> getScanSsid(getScanSsid_cb _hidl_cb) override;
    Return<void> getKeyMgmt(getKeyMgmt_cb _hidl_cb) override;
    Return<void> getProto(getProto_cb _hidl_cb) override;
    Return<void> getAuthAlg(getAuthAlg_cb _hidl_cb) override;
    Return<void> getGroupCipher(getGroupCipher_cb _hidl_cb) override;
    Return<void> getPairwiseCipher(getPairwiseCipher_cb _hidl_cb) override;
    Return<void> getPskPassphrase(getPskPassphrase_cb _hidl_cb) override;
    Return<void> getPsk(getPsk_cb _hidl_cb) override;
    Return<void> getWepKey(uint32_t keyIdx, getWepKey_cb _hidl_cb) override;
    Return<void> getWepTxKeyIdx(getWepTxKeyIdx_cb _hidl_cb) override;
    Return<void> getRequirePmf(getRequirePmf_cb _hidl_cb) override;
    Return<void> getEapMethod(getEapMethod_cb _hidl_cb) override;
    Return<void> getEapPhase2Method(getEapPhase2Method_cb _hidl_cb) override;
    Return<void> getEapIdentity(getEapIdentity_cb _hidl_cb) override;
    Return<void> getEapAnonymousIdentity(getEapAnonymousIdentity_cb _hidl_cb) override;
    Return<void> getEapPassword(getEapPassword_cb _hidl_cb) override;
    Return<void> getEapCACert(getEapCACert_cb _hidl_cb) override;
    Return<void> getEapCAPath(getEapCAPath_cb _hidl_cb) override;
    Return<void> getEapClientCert(getEapClientCert_cb _hidl_cb) override;
    Return<void> getEapPrivateKeyId(getEapPrivateKeyId_cb _hidl_cb) override;
    Return<void> getEapSubjectMatch(getEapSubjectMatch_cb _hidl_cb) override;
    Return<void> getEapAltSubjectMatch(getEapAltSubjectMatch_cb _hidl_cb) override;
    Return<void> getEapEngine(getEapEngine_cb _hidl_cb) override;
    Return<void> getEapEngineID(getEapEngineID_cb _hidl_cb) override;
    Return<void> getEapDomainSuffixMatch(getEapDomainSuffixMatch_cb _hidl_cb) override;
    Return<void> getIdStr(getIdStr_cb _hidl_cb) override;
    Return<void> getWpsNfcConfigurationToken(getWpsNfcConfigurationToken_cb _hidl_cb) override;

    // Actions & Handlers
    Return<void> enable(bool noConnect, enable_cb _hidl_cb) override;
    Return<void> disable(disable_cb _hidl_cb) override;
    Return<void> select(select_cb _hidl_cb) override;
    Return<void> sendNetworkEapSimGsmAuthResponse(const hidl_vec<NetworkResponseEapSimGsmAuthParams>& params, sendNetworkEapSimGsmAuthResponse_cb _hidl_cb) override;
    Return<void> sendNetworkEapSimGsmAuthFailure(sendNetworkEapSimGsmAuthFailure_cb _hidl_cb) override;
    Return<void> sendNetworkEapSimUmtsAuthResponse(const NetworkResponseEapSimUmtsAuthParams& params, sendNetworkEapSimUmtsAuthResponse_cb _hidl_cb) override;
    Return<void> sendNetworkEapSimUmtsAutsResponse(const hidl_array<uint8_t, 14>& auts, sendNetworkEapSimUmtsAutsResponse_cb _hidl_cb) override;
    Return<void> sendNetworkEapSimUmtsAuthFailure(sendNetworkEapSimUmtsAuthFailure_cb _hidl_cb) override;
    Return<void> sendNetworkEapIdentityResponse(const hidl_vec<uint8_t>& identity, sendNetworkEapIdentityResponse_cb _hidl_cb) override;

    bool mIsEnabled = false;

    std::string mIdStr;
    std::string mPskPassphrase;

    std::vector<uint8_t> mSsid = {0x76, 0x69, 0x72, 0x74, 0x77, 0x69, 0x66, 0x69};
    std::array<uint8_t, 6> mBssid = {{0x00, 0x11, 0x22, 0x33, 0x44, 0x65}};
};

} // namespace implementation
