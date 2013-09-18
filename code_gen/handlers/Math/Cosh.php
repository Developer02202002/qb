<?php

class Cosh extends Handler {

	use MultipleAddressMode, UnaryOperator, FloatingPointOnly;
	
	protected function getActionOnUnitData() {
		$type = $this->getOperandType(2);
		$cType = $this->getOperandCType(2);
		$f = ($type == 'F32') ? 'f' : '';
		return "res = cosh$f(op1);";

	}
}

?>