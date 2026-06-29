#ifndef VOIDCOIN_QT_BROADCASTVAULTPAYMENTDIALOG_H
#define VOIDCOIN_QT_BROADCASTVAULTPAYMENTDIALOG_H

#include <QDialog>

class QPushButton;
class QTextEdit;
class WalletModel;

class BroadcastVaultPaymentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BroadcastVaultPaymentDialog(WalletModel* wallet_model, QWidget* parent = nullptr);

private:
    void openPackage();
    void finalizePackage();
    void broadcastTransaction();

    WalletModel* m_wallet_model{nullptr};

    QString m_package_json;
    QString m_final_tx_hex;

    QPushButton* m_open_button{nullptr};
    QPushButton* m_finalize_button{nullptr};
    QPushButton* m_broadcast_button{nullptr};
    QTextEdit* m_package_text{nullptr};
    QTextEdit* m_status_text{nullptr};
};

#endif // VOIDCOIN_QT_BROADCASTVAULTPAYMENTDIALOG_H
