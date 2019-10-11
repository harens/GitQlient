#pragma once

/****************************************************************************************
 ** GitQlient is an application to manage and operate one or several Git repositories. With
 ** GitQlient you will be able to add commits, branches and manage all the options Git provides.
 ** Copyright (C) 2019  Francesc Martinez
 **
 ** LinkedIn: www.linkedin.com/in/cescmm/
 ** Web: www.francescmm.com
 **
 ** This library is free software; you can redistribute it and/or
 ** modify it under the terms of the GNU Lesser General Public
 ** License as published by the Free Software Foundation; either
 ** version 3 of the License, or (at your option) any later version.
 **
 ** This library is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 ** Lesser General Public License for more details.
 **
 ** You should have received a copy of the GNU Lesser General Public
 ** License along with this library; if not, write to the Free Software
 ** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 ***************************************************************************************/

#include <QProcess>

class AGitProcess : public QProcess
{
   Q_OBJECT

signals:
   void eof();
   void procDataReady(const QByteArray &data);

public:
   explicit AGitProcess(const QString &workingDir, bool reportErrorsEnabled);

   virtual bool run(const QString &command, QString &output) = 0;
   void onCancel();

protected:
   QString *mRunOutput = nullptr;
   QString mWorkingDirectory;
   QString mErrorOutput;
   QString mCommand;
   bool mErrorReportingEnabled = false;
   bool mErrorExit = false;
   bool mCanceling = false;
   bool execute(const QString &command);
   virtual void onFinished(int, QProcess::ExitStatus exitStatus);

private:
   void onReadyStandardOutput();
};
