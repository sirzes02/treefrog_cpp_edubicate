#include <QtCore>
#include <TreeFrogView>
#include "objects/t000token.h" 
#include "applicationhelper.h"
#include "commons.h"

class T_VIEW_EXPORT t000token_showView : public TActionView
{
public:
  t000token_showView() : TActionView() { }
  QString toString();
};

QString t000token_showView::toString()
{
  responsebody.reserve(1390);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(T000Token, t000Token);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing T000 Token</h1>\n<dt>C000 ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(t000Token.c000Id());
  responsebody += QStringLiteral("</dd><br>\n<dt>C000 Token</dt><dd>");
  responsebody += THttpUtility::htmlEscape(t000Token.c000Token());
  responsebody += QStringLiteral("</dd><br>\n<dt>C001 ID Usuario</dt><dd>");
  responsebody += THttpUtility::htmlEscape(t000Token.c001IdUsuario());
  responsebody += QStringLiteral("</dd><br>\n<dt>C000 Fecha Creacion</dt><dd>");
  responsebody += THttpUtility::htmlEscape(t000Token.c000FechaCreacion());
  responsebody += QStringLiteral("</dd><br>\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", t000Token.c000Id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(t000token_showView)

