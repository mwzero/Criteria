# This Dockerfile is used to build an headless vnc image based on Fedora

### first time, use the first line, ortherwize, if you have docker image [docker.io/fedora], then use the second line
FROM fedora
#FROM docker.io/fedora

MAINTAINER http://fedoraproject.org/wiki/Cloud
ENV REFRESHED_AT 2017-08-12

LABEL io.k8s.description="Headless VNC Container with Xfce window manager, firefox and chromium" \
      io.k8s.display-name="Headless VNC Container based on Fedora" \
      io.openshift.expose-services="6901:http,5901:xvnc" \
      io.openshift.tags="vnc, fedora, xfce" \
      io.openshift.non-scalable=true

## Connection ports for controlling the UI:
# VNC port:5901
# noVNC webport, connect via http://IP:6901/?password=123456
ENV DISPLAY :1
ENV VNC_PORT 5901
ENV NO_VNC_PORT 6901
EXPOSE $VNC_PORT $NO_VNC_PORT

ENV HOME /headless
ENV STARTUPDIR /dockerstartup
WORKDIR $HOME

### ENVrionment config
ENV NO_VNC_HOME $HOME/noVNC
ENV VNC_COL_DEPTH 24
ENV VNC_RESOLUTION 1280x1024
ENV VNC_PW 123456

### cBPM
#------------------------------------------------------
RUN dnf -y update && dnf clean all
RUN dnf -y install nginx && dnf clean all
RUN dnf -y install mariadb && dnf clean all
RUN dnf -y install mariadb-server && dnf clean all
RUN dnf -y install mysql-devel && dnf clean all
RUN dnf -y install spawn-fcgi && dnf clean all
RUN dnf -y install fcgi && dnf clean all
RUN dnf -y install tigervnc-server && dnf clean all
RUN dnf -y install hostname && dnf clean all
RUN dnf -y install policycoreutils-python-utils && dnf clean all

RUN echo "export WF_HOME=/usr/share/nginx/html" >> /etc/profile
RUN echo "export CRITERIA_HOME=/usr/share/nginx/html" >> /etc/profile

#RUN mkdir -p /opt/cBPM/criteria-lin/lib
#RUN rm -rf /usr/share/nginx/html

ADD nginx.conf /etc/nginx/
ADD html/ /usr/share/nginx/html/
ADD executer /usr/share/nginx/html/
#ADD executer /opt/cBPM/criteria-lin/lib/
ADD libLibraries.so /usr/lib64/
ADD libWorkflowEngineD.so /usr/lib64/
ADD libxerces-c-3.1.so /usr/lib64/

RUN chown nginx.nginx -R /usr/share/nginx/html/
RUN chmod 755 -R /usr/share/nginx/html/
RUN chown root.root -R /usr/share/nginx/html/executer

### // RUN systemctl restart mariadb.service  # systemctl can not work in docker
#RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql
#RUN mysqladmin -uroot -p password '123456'
#RUN mysqladmin -u root -p'123456' create criteria
#RUN mysql -uroot -p'123456' < /usr/share/nginx/html/database/scripts/mysql/criteria_mysql.sql
#RUN mysql -uroot -p'123456' criteria < /usr/share/nginx/html/database/scripts/mysql/dm_mysql.sql
#------------------------------------------------------


### Add all install scripts for further steps
ENV INST_SCRIPTS $HOME/install
ADD dockerfiles/headless/install/ $INST_SCRIPTS/
RUN find $INST_SCRIPTS -name '*.sh' -exec chmod a+x {} +

### Install some common tools
RUN $INST_SCRIPTS/tools.sh

### Install xvnc-server & noVNC - HTML5 based VNC viewer
#RUN $INST_SCRIPTS/tigervnc.sh
#RUN $INST_SCRIPTS/no_vnc.sh

### Install firfox and chrome browser
#RUN $INST_SCRIPTS/firefox.sh
#RUN $INST_SCRIPTS/chrome.sh

### Install xfce UI
RUN $INST_SCRIPTS/xfce_ui.sh
ADD dockerfiles/headless/wm_startup.sh $HOME/

### configure startup
RUN $INST_SCRIPTS/libnss_wrapper.sh
ADD dockerfiles/dockerstartup $STARTUPDIR
RUN $INST_SCRIPTS/set_user_permission.sh $STARTUPDIR $HOME
# ztg del
#USER 1984

# del root password
RUN sed -i '/0/s/x//g' /etc/passwd

ENTRYPOINT ["/dockerstartup/vnc_startup.sh"]
CMD ["--tail-log"]

