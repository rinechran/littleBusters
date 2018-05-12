#include "Mysql.h"


std::unordered_map<KUD::MYSQL::ErrorCode, std::string> KUD::MYSQL::ErrorCodeStringMapping = {
	{ KUD::MYSQL::ErrorCode::CONNECTED ,"CONNECTED" },
	{ KUD::MYSQL::ErrorCode::NOT_CONNECT ,"NOT_CONNECT" },
	{ KUD::MYSQL::ErrorCode::CONNERCT_ERROR ,"CONNERCT_ERROR" }
};

KUD::MYSQL::ImPort::ImPort() : port(3306) {}

KUD::MYSQL::ImPort::ImPort(unsigned int othPort) : port(othPort) {}

KUD::MYSQL::ImFlog::ImFlog() : flog(0) {}

KUD::MYSQL::ImFlog::ImFlog(unsigned int othFlog) : flog(othFlog) {}

KUD::MYSQL::ImSocket::ImSocket() : sock(nullptr) {}

KUD::MYSQL::ImSocket::ImSocket(const char * othFlog) : sock(othFlog) {}

KUD::MYSQL::Mysql::Mysql() : _IsSetting(false) {
	if (!_IsSetting) {
		_IsSetting = mysql_init(nullptr);
	}
}

KUD::MYSQL::ErrorCode KUD::MYSQL::Mysql::connect(ConnetSetting setting) {
	_Setting = setting;
	ConnectMove(std::move(setting));
	if (!_IsSetting) {
		return ErrorCode::NOT_CONNECT;
	}

	auto isResult = mysql_real_connect(_Connector, _Setting.host.c_str(), _Setting.id.c_str()
		, _Setting.passwd.c_str(), _Setting.database.c_str(), _Setting.port
		, _Setting.socket, _Setting.flog);

	if (!isResult) {
		return ErrorCode::CONNERCT_ERROR;
	}
	return ErrorCode::CONNECTED;
}

KUD::MYSQL::ErrorCode KUD::MYSQL::Mysql::mysql_query(std::string & query) {
	auto i = ::mysql_query(_Connector, query.c_str());
	if (i == 0) {
		return ErrorCode::QUERY_SUCCESS;
	}
	return ErrorCode::QUERY_FAIL;
}

KUD::MYSQL::Mysql::~Mysql() {
	if (_IsSetting) {
		mysql_close(_Connector);
	}
}

void KUD::MYSQL::Mysql::ConnectMove(ConnetSetting && oth) {
	_Setting.host = std::move(oth.host);
	_Setting.id = std::move(oth.id);
	_Setting.passwd = std::move(oth.passwd);
	_Setting.port = oth.port;
	_Setting.socket = oth.socket;
	_Setting.flog = oth.flog;

}

std::string KUD::MYSQL::to_string(ErrorCode code) {
	auto it = ErrorCodeStringMapping.find(code);
	if (it != ErrorCodeStringMapping.end()) {
		return it->second;
	}
	return "";
}
