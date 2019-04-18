/*
 * Copyright (C) 2017 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#if ENABLE(APPLE_PAY) && ENABLE(PAYMENT_REQUEST)

#include "ApplePayRequest.h"
#include "PaymentHandler.h"
#include "PaymentSession.h"
#include <wtf/Noncopyable.h>
#include <wtf/Ref.h>

namespace WebCore {

class PaymentRequest;

class ApplePayPaymentHandler final : public PaymentHandler, public PaymentSession {
public:
    static bool handlesIdentifier(const PaymentRequest::MethodIdentifier&);
    static bool hasActiveSession(Document&);

private:
    friend class PaymentHandler;
    explicit ApplePayPaymentHandler(PaymentRequest&);

    // PaymentHandler
    ExceptionOr<void> convertData(JSC::ExecState&, JSC::JSValue&&) final;
    ExceptionOr<void> show(Document&) final;
    void hide(Document&) final;
    void canMakePayment(Document&, WTF::Function<void(bool)>&& completionHandler) final;

    // PaymentSession
    void validateMerchant(const URL&) final;
    void didAuthorizePayment(const Payment&) final { }
    void didSelectShippingMethod(const ApplePaySessionPaymentRequest::ShippingMethod&) final { }
    void didSelectShippingContact(const PaymentContact&) final { }
    void didSelectPaymentMethod(const PaymentMethod&) final { }
    void didCancelPaymentSession() final { }

    Ref<PaymentRequest> m_paymentRequest;
    std::optional<ApplePayRequest> m_applePayRequest;
};

} // namespace WebCore

#endif // ENABLE(APPLE_PAY) && ENABLE(PAYMENT_REQUEST)