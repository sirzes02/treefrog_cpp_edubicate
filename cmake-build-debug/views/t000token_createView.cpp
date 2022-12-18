#include <QtCore>
#include <TreeFrogView>
#include "objects/t000token.h" 
#include "applicationhelper.h"
#include "commons.h"

class T_VIEW_EXPORT t000token_createView : public TActionView
{
public:
  t000token_createView() : TActionView() { }
  QString toString();
};

QString t000token_createView::toString()
{
  responsebody.reserve(1525);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, t000Token);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New T000 Token</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>C000 Token<br><input name=\"t000Token[c000Token]\" value=\"");
  responsebody += THttpUtility::htmlEscape(t000Token["c000Token"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>C001 ID Usuario<br><input name=\"t000Token[c001IdUsuario]\" value=\"");
  responsebody += THttpUtility::htmlEscape(t000Token["c001IdUsuario"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>C000 Fecha Creacion<br><input name=\"t000Token[c000FechaCreacion]\" value=\"");
  responsebody += THttpUtility::htmlEscape(t000Token["c000FechaCreacion"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(t000token_createView)

