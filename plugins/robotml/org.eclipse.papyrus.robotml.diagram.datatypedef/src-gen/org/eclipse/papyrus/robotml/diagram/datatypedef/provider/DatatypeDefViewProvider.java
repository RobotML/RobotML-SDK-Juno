/*****************************************************************************
 * Copyright (c) 2012 CEA LIST.
 *
 *    
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the CeCILL-C Free Software License v1.0
 * which accompanies this distribution, and is available at
 * http://www.cecill.info/licences/Licence_CeCILL-C_V1-en.html
 *
 * Contributors:
 *  Saadia DHOUIB (CEA LIST) - Initial API and implementation
 *
 *****************************************************************************/
package org.eclipse.papyrus.robotml.diagram.datatypedef.provider;

import org.eclipse.core.runtime.IAdaptable;
import org.eclipse.gmf.runtime.diagram.core.providers.AbstractViewProvider;
import org.eclipse.gmf.runtime.diagram.core.services.view.CreateDiagramViewOperation;
import org.eclipse.papyrus.robotml.diagram.datatypedef.Activator;
import org.eclipse.papyrus.robotml.diagram.datatypedef.edit.part.DatatypeDefEditPart;
import org.eclipse.papyrus.robotml.diagram.datatypedef.factory.DatatypeDefViewFactory;

public class DatatypeDefViewProvider extends AbstractViewProvider {

	@Override
	protected boolean provides(CreateDiagramViewOperation operation) {
		
		if(DatatypeDefEditPart.DIAGRAM_ID.equals(operation.getSemanticHint())) {
			return true;
		}
		
		return false;
	}

	@Override
	protected Class<?> getDiagramViewClass(IAdaptable semanticAdapter, String diagramKind) {
		if(DatatypeDefEditPart.DIAGRAM_ID.equals(diagramKind)) {
			return DatatypeDefViewFactory.class;
		}

		Activator.log.error(new Exception("Could not create View."));
		return null;
	}
}
