package org.yakindu.sct.examples.lightswitch;

import org.yakindu.sct.examples.basic.tutorial._02_LightSwitch;

public class LightSwitch_02 {

	public static void main(String[] args) throws InterruptedException {
		_02_LightSwitch sm = new _02_LightSwitch();

		sm.enter();

		for (int i = 0; i < 10; i++) {
			sm.user().raiseOperate();

			if (sm.isStateActive(_02_LightSwitch.State.MAIN_REGION_ON)) {
				System.out.println("Light is On");
			} else if (sm.isStateActive(_02_LightSwitch.State.MAIN_REGION_OFF)) {
				System.out.println("Light is Off");
			}

		}
	}
}
