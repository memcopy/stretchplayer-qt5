/*
 * Copyright(c) 2009 by Gabriel M. Beddingfield <gabriel@teuton.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "config.h"

#include <QApplication>

#include "Configuration.hpp"
#include "PlayerWidget.hpp"
#include <iostream>
#include <QPlastiqueStyle>
#include <memory>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    StretchPlayer::Configuration config(argc, argv);

    if(config.help() || ( !config.ok() )) {
	config.usage();
	if( !config.ok() ) return -1;
	return 0;
    }

    if( !config.quiet() ) {
	config.copyright();
    }

    std::auto_ptr<StretchPlayer::PlayerWidget> pw;
    pw.reset(new StretchPlayer::PlayerWidget);

    app.setStyle( new QPlastiqueStyle );

    pw->show();

    if(argc > 1) {
	QString fn(argv[1]);
	std::cout << "Loading file " << argv[1] << std::endl;
	pw->load_song(fn);
    }

    app.exec();

    return 0;
}
