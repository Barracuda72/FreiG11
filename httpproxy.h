/***************************************************************************
 *   Copyright (C) 2007 by Alexander S. Salieff                            *
 *   salieff@mail.ru                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef _HTTP_PROXY_H_
#define _HTTP_PROXY_H_

#include <string>

using namespace std;

class HttpProxy{
 public:
  HttpProxy(void);
  HttpProxy(string ahost, int aport, string auid="", string apass="");
  ~HttpProxy();
  
  void setHost(string ahost);
  void setPort(int aport);
  void setUser(string auid);
  void setPassword(string apass);
  
  int connectTo(string ahost, int aport);
  
 private:
  bool priv_connectToProxy(void);
  bool priv_doQuery(void);

  string priv_createProxyQuery(void);
  bool priv_checkProxyAnswer(string answ);
  
  string proxy_host;
  int proxy_port;
  string proxy_user;
  string proxy_password;
  
  string dst_host;
  int dst_port;
  
  int sock;
};

#endif
