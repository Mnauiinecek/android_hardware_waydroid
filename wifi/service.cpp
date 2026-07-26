#include <android/log.h>
#include <hidl/HidlTransportSupport.h>
#include <utils/StrongPointer.h>
#include <utils/Log.h>
#include "Supplicant.h"

using android::status_t;
using android::OK;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::hardware::wifi::supplicant::V1_0::ISupplicant;
using android::hardware::wifi::supplicant::V1_0::implementation::Supplicant;

int main() {
    status_t status;
    android::sp<ISupplicant> service = new Supplicant();

    if (service == nullptr) {
        ALOGE("Can not create an instance of Supplicant HAL Iface, exiting.");
        goto shutdown;
    }

    configureRpcThreadpool(1, true /* callerWillJoin */);

    if ((status = service->registerAsService()) != OK) {
        ALOGE("Could not register service for Supplicant HAL Iface (%d).", status);
        goto shutdown;
    }

    ALOGI("Supplicant Service is ready");
    joinRpcThreadpool();
    // Should not pass this line

shutdown:
    // In normal operation, we don't expect the thread pool to exit

    ALOGE("Power Service is shutting down");
    return 1;
}
