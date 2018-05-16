#include "Mysql.h"


std::unordered_map<KUD::MYSQL::ErrorCode, std::string> KUD::MYSQL::ErrorCodeStringMapping = {
	{ KUD::MYSQL::ErrorCode::CONNECTED ,"CONNECTED" },
	{ KUD::MYSQL::ErrorCode::NOT_CONNECT ,"NOT_CONNECT" },
	{ KUD::MYSQL::ErrorCode::CONNERCT_ERROR ,"CONNERCT_ERROR" }
};

KUD::MYSQL::ImplePort::ImplePort() : port(3306) {}

KUD::MYSQL::ImplePort::ImplePort(unsigned int othPort) : port(othPort) {}

KUD::MYSQL::impleFlog::impleFlog() : flog(0) {}

KUD::MYSQL::impleFlog::impleFlog(unsigned int othFlog) : flog(othFlog) {}

KUD::MYSQL::impleSocket::impleSocket() : sock(nullptr) {}

KUD::MYSQL::impleSocket::impleSocket(const char * othFlog) : sock(othFlog) {}

KUD::MYSQL::Mysql::Mysql() : _isSetting(false) {
	if (!_isSetting) {
		_isSetting = mysql_init(nullptr);
	}
}

KUD::MYSQL::ErrorCode KUD::MYSQL::Mysql::connect(ConnectSetting setting) {
	_setting = setting;
	ConnectMove(std::move(setting));
	if (!_isSetting) {
		return ErrorCode::NOT_CONNECT;
	}

	auto isResult = mysql_real_connect(_connector, _setting.host.c_str(), _setting.id.c_str()
		, _setting.passwd.c_str(), _setting.database.c_str(), _setting.port
		, _setting.socket, _setting.flog);

	if (!isResult) {
		return ErrorCode::CONNERCT_ERROR;
	}
	return ErrorCode::CONNECTED;
}

KUD::MYSQL::ErrorCode KUD::MYSQL::Mysql::mysql_query(std::string & query) {
	auto i = ::mysql_query(_connector, query.c_str());
	if (i == 0) {
		return ErrorCode::QUERY_SUCCESS;
	}
	return ErrorCode::QUERY_FAIL;
}

KUD::MYSQL::Mysql::~Mysql() {
	if (_isSetting) {
		mysql_close(_connector);
	}
}

void KUD::MYSQL::Mysql::ConnectMove(ConnectSetting && oth) {
	_setting.host = std::move(oth.host);
	_setting.id = std::move(oth.id);
	_setting.passwd = std::move(oth.passwd);
	_setting.port = oth.port;
	_setting.socket = oth.socket;
	_setting.flog = oth.flog;

}

std::string KUD::MYSQL::to_string(ErrorCode code) {
	auto it = ErrorCodeStringMapping.find(code);
	if (it != ErrorCodeStringMapping.end()) {
		return it->second;
	}
	return "";
}
