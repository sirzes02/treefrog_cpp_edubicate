#include <QtCore>
#include <TreeFrogView>
#include "objects/t000token.h" 
#include "applicationhelper.h"
#include "commons.h"

class T_VIEW_EXPORT t000token_indexView : public TActionView
{
public:
  t000token_indexView() : TActionView() { }
  QString toString();
};

QString t000token_indexView::toString()
{
  responsebody.reserve(1834);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n\n<h1>Listing T000 Token</h1>\n\n");
  responsebody += QVariant(linkTo("Create a new T000 Token", urla("create"))).toString();
  responsebody += QStringLiteral("<br>\n<br>\n<table border=\"1\" cellpadding=\"5\" style=\"border: 1px #d0d0d0 solid; border-collapse: collapse;\">\n  <tr>\n    <th>C000 ID</th>\n    <th>C000 Token</th>\n    <th>C001 ID Usuario</th>\n    <th>C000 Fecha Creacion</th>\n  </tr>\n");
  tfetch(QList<T000Token>, t000TokenList);
  for (const auto &i : t000TokenList) {
  responsebody += QStringLiteral("  <tr>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.c000Id());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.c000Token());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.c001IdUsuario());
  responsebody += QStringLiteral("</td>\n    <td>");
  responsebody += THttpUtility::htmlEscape(i.c000FechaCreacion());
  responsebody += QStringLiteral("</td>\n    <td>\n      ");
  responsebody += QVariant(linkTo("Show", urla("show", i.c000Id()))).toString();
  responsebody += QStringLiteral("\n      ");
  responsebody += QVariant(linkTo("Edit", urla("save", i.c000Id()))).toString();
  responsebody += QStringLiteral("\n      ");
  responsebody += QVariant(linkTo("Remove", urla("remove", i.c000Id()), Tf::Post, "confirm('Are you sure?')")).toString();
  responsebody += QStringLiteral("\n    </td>\n  </tr>\n");
  };
  responsebody += QStringLiteral("</table>\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(t000token_indexView)

