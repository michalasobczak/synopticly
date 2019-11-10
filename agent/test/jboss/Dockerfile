FROM jboss/wildfly:11.0.0.Final
# packages
USER root
RUN yum update -y
RUN yum install curl net-tools mc procps sudo gcc build-essential less -y
RUN yum groupinstall "Development tools" -y
RUN yum install git-core zlib zlib-devel gcc-c++ patch readline readline-devel libyaml-devel libffi-devel openssl-devel make bzip2 autoconf automake libtool bison curl sqlite-devel -y

# synopticly
RUN yum install lua lua-devel lua-static wget -y
RUN cd /opt && wget http://download-ib01.fedoraproject.org/pub/epel/7/x86_64/Packages/l/lua-socket-3.0-0.17.rc1.el7.x86_64.rpm
RUN cd /opt && rpm -ivh lua-socket-3.0-0.17.rc1.el7.x86_64.rpm
RUN ln -s /usr/lib64/liblua-5.1.so /usr/lib64/liblua5.1.so.0
RUN echo "cd /opt && wget https://github.com/michalasobczak/synopticly/raw/develop/agent/Debug/synopticly-agent && chmod +x /opt/synopticly-agent" >> /opt/runner.sh
RUN cd /opt/ && echo '{"api_url": "synopticly.mplatform.local:4567"}' >> /opt/synopticly_config.json
RUN echo "/opt/synopticly-agent &" >> /opt/runner.sh

RUN chmod a+x /opt/runner.sh
ENTRYPOINT bash -l -c "/opt/runner.sh" 

