#include <iostream>
#include <string>

class Certificate {
    private:
        unsigned int CertificatedID;
        std::string CertificateName;
        std::string CertificateRank;
        std::string CertificatedDate;
    public:
        Certificate(int id,std:: string name,std:: string rank,std:: string date)
            : CertificatedID(id), CertificateName(name), CertificateRank(rank), CertificatedDate(date) {};

        void ShowCertificate() const {
            std::cout << "CertificatedID: " << CertificatedID << ", CertificatedName: " << CertificateName
                 << ", CertificatedRank: " << CertificateRank << ", CertificatedDate: " << CertificatedDate << std::endl;
        }
};