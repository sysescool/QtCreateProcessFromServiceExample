#include <QCoreApplication>
#include <QLoggingCategory>

#include "qtservice.h"

Q_LOGGING_CATEGORY(lcMain, "Main")

class QServiceExample final : public QtService<QCoreApplication>
{
public:
    QServiceExample(int argc, char **argv)
        : QtService<QCoreApplication>(argc, argv, "QServiceExample")
    {
        setServiceDescription("CloudAgentQ Service");
    }

    ~QServiceExample() {}

    void createApplication(int &argc, char **argv) override
    {
        qInfo(lcMain) << "1. createApplication";
        QtService<QCoreApplication>::createApplication(argc, argv);
    }

    int executeApplication() override
    {
        qInfo(lcMain) << "2. executeApplication";
        return QtService<QCoreApplication>::executeApplication();
    }

    void start() override { qInfo(lcMain) << "3. start"; }

    void stop() override { qInfo(lcMain) << "stop service as request"; }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "1";
    // run with -h or -help to learn how to use.
    QServiceExample serviceExample(argc, argv);
    qInfo() << "2";

    return serviceExample.exec();
}
